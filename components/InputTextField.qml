import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

TextField {
    Layout.fillWidth: true
    onAcceptableInputChanged:
        color = acceptableInput ? "black" : "red";
    background: Rectangle {
        border.color: angleField.acceptableInput ?
            (angleField.activeFocus ? "#21be2b" : "gray") : "red"
        border.width: angleField.activeFocus ? 2 : 1
        radius: 3
    }
}
