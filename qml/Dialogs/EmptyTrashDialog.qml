
import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import FishUI 1.0 as FishUI
import Cutefish.FileManager 1.0

FishUI.Window {
    id: control

    title: qsTr("File Manager")
    flags: Qt.Dialog | Qt.FramelessWindowHint | Qt.WindowStaysOnTopHint
    minimizeButtonVisible: false
    visible: true

    property int contentWidth: 300 + FishUI.Units.largeSpacing * 2
    property int contentHeight: _mainLayout.implicitHeight + control.header.height + FishUI.Units.largeSpacing

    width: contentWidth
    height: contentHeight

//    x: Screen.virtualX + (Screen.width - contentWidth) / 2
//    y: Screen.virtualY + (Screen.height - contentHeight) / 2

    minimumWidth: contentWidth
    minimumHeight: contentHeight
    maximumWidth: contentWidth
    maximumHeight: contentHeight

    headerBackground.color: FishUI.Theme.secondBackgroundColor

    DragHandler {
        target: null
        acceptedDevices: PointerDevice.GenericPointer
        grabPermissions: PointerHandler.CanTakeOverFromItems | PointerHandler.CanTakeOverFromHandlersOfDifferentType | PointerHandler.ApprovesTakeOverByAnything
        onActiveChanged: if (active) { control.helper.startSystemMove(control) }
    }

    Fm {
        id: fm
    }

    Rectangle {
        anchors.fill: parent
        color: FishUI.Theme.secondBackgroundColor
    }

    ColumnLayout {
        id: _mainLayout
        anchors.fill: parent
        anchors.topMargin: 0
        anchors.leftMargin: FishUI.Units.largeSpacing
        anchors.rightMargin: FishUI.Units.largeSpacing
        anchors.bottomMargin: FishUI.Units.largeSpacing
        spacing: FishUI.Units.largeSpacing

        Label {
            text: qsTr("Do you want to permanently delete all files from the Trash?")
            Layout.fillWidth: true
            wrapMode: Text.Wrap
        }

        RowLayout {
            spacing: FishUI.Units.largeSpacing

            Button {
                text: qsTr("Cancel")
                Layout.fillWidth: true
                onClicked: control.close()
            }

            Button {
                text: qsTr("Empty Trash")
                focus: true
                Layout.fillWidth: true
                onClicked: {
                    fm.emptyTrash()
                    control.close()
                }
                flat: true
            }
        }
    }
}
