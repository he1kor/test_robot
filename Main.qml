import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "components"



ApplicationWindow {

    Component.onCompleted: Qt.style = "Fusion"

    width: 300
    height: 400
    visible: true
    minimumWidth: width
    maximumWidth: width
    minimumHeight: height
    maximumHeight: height
    title: "DH-Model Solver"

    ColumnLayout {

        id: root

        anchors.fill: parent
        anchors.margins: 20
        anchors.leftMargin: 70
        anchors.rightMargin: 70
        spacing: 5
        Label {
            text: "Input:"
            font.bold: true
        }
        Repeater {
            id: inputAngles
            model: backend.robotController.jointCount

            property bool allInputsValid: checkAllInputsValid()
            function checkAllInputsValid() {
                for (var i = 0; i < inputAngles.count; ++i) {
                    var item = inputAngles.itemAt(i);
                    if (!item){
                        continue;
                    }
                    var angleField = item.angleField;
                    if (!angleField || !angleField.acceptableInput) {
                        return false;
                    }
                }
                return true;
            }
            function onInputChanged() {
                var newVal = checkAllInputsValid();
                if (allInputsValid !== newVal) {
                    allInputsValid = newVal;
                }
            }
            delegate: RowLayout {
                property alias angleField: angleField
                required property int index
                Label {
                    text: "Theta " + (index + 1) + ":"
                }
                Layout.fillWidth: true

                InputTextField {
                    id: angleField
                    placeholderText: "(-180 to 180)"
                    placeholderTextColor: "grey"
                    validator: DoubleValidator {
                        bottom: -180.0
                        top: 180.0
                        decimals: 2
                        notation: DoubleValidator.StandardNotation
                        locale: Qt.locale().name
                    }
                    property real value: text === "-" ? 0 : (Number.fromLocaleString(Qt.locale(), text) || 0)

                    onTextChanged: inputAngles.onInputChanged();
                }
            }
        }
        Button {
            text: "Calculate"
            Layout.fillWidth: true
            enabled: inputAngles.allInputsValid
            onClicked: {
                const angles = [];
                for (let i = 0; i < inputAngles.count; i++) {
                    angles.push(inputAngles.itemAt(i).angleField.value);
                }
                backend.robotController.setJointAngles(angles);
            }
        }

        Rectangle {
            Layout.fillWidth: true
            height: 1
            color: "gray"
            Layout.topMargin: 5
            Layout.bottomMargin: 5
        }


        Label {
            text: "Results:"
            font.bold: true
        }

        RowLayout {
            Label { text: "X:" }
            OutputTextField {
                id: resultX
                text: backend.robotController.lastJointPos.x.toFixed(4)
            }
        }
        RowLayout {
            Label { text: "Y:" }
            OutputTextField {
                id: resultY
                text: backend.robotController.lastJointPos.y.toFixed(4)
            }
        }
        RowLayout {
            Label { text: "Z:" }
            OutputTextField {
                id: resultZ
                text: backend.robotController.lastJointPos.z.toFixed(4)
            }
        }
    }
}
