
import QtQuick 2.12
import FishUI 1.0 as FishUI

Item {
    id: control
    width: 24
    height: 24

    property alias source: _image.source
    property color backgroundColor: FishUI.Theme.darkMode ? Qt.lighter(FishUI.Theme.secondBackgroundColor, 1.3)
                                                          : FishUI.Theme.secondBackgroundColor
    property color hoveredColor: FishUI.Theme.darkMode ? Qt.lighter(FishUI.Theme.secondBackgroundColor, 1.7)
                                                   : Qt.darker(FishUI.Theme.secondBackgroundColor, 1.2)
    property color pressedColor: FishUI.Theme.darkMode ? Qt.lighter(FishUI.Theme.secondBackgroundColor, 1.4)
                                                     : Qt.darker(FishUI.Theme.secondBackgroundColor, 1.3)

    signal clicked()

    Rectangle {
        id: _background
        anchors.fill: parent
        radius: FishUI.Theme.smallRadius
        color: _mouseArea.pressed ? pressedColor : _mouseArea.containsMouse ? control.hoveredColor : control.backgroundColor
    }

    Image {
        id: _image
        anchors.centerIn: parent
        width: 18
        height: width
        sourceSize: Qt.size(width, height)
        smooth: false
        antialiasing: true
    }

    MouseArea {
        id: _mouseArea
        anchors.fill: parent
        hoverEnabled: true
        acceptedButtons: Qt.LeftButton
        onClicked: control.clicked()
    }
}
