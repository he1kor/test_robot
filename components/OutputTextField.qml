import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

TextField {
    readOnly: true
    Layout.fillWidth: true
    color: "black"
    background: Rectangle {
        border.color: "gray"
        border.width: 1
        radius: 3
    }
}
