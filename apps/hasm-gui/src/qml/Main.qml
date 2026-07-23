import QtQuick
import QtQuick.Controls

ApplicationWindow {
    width: 400
    height: 300

    visible: true

    title: qsTr("hasm")

    Label {
        anchors.centerIn: parent

        text: qsTr("hello there!")
    }
}
