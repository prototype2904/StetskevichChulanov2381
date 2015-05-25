import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    id: applicationWindow1
    visible: true
    width: 1000
    height: 600
    opacity: 1.3
    title: qsTr("Hello World")

    menuBar: MenuBar {
        Menu {
            visible: true
            title: qsTr("File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: console.log("Open action triggered");
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    Image {
        id: wall
        x: 498
        y: 148
        width: 640
        height: 282
        sourceSize.height: 700
        sourceSize.width: 1200
        fillMode: Image.PreserveAspectFit
        anchors.verticalCenterOffset: -5
        anchors.rightMargin: 16
        anchors.bottomMargin: -71
        anchors.leftMargin: -8
        anchors.topMargin: -71
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.top: parent.top
        anchors.left: parent.left
        source: "image/wallpaper.png"
        visible: true;
    }

    Image {
        id: board
        x: 131
        y: 31
        width: 593
        height: 517
        anchors.verticalCenterOffset: 0
        anchors.horizontalCenterOffset: -196
        anchors.rightMargin: 282
        anchors.bottomMargin: 62
        sourceSize.width: 616
        visible: true
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.top: parent.top
        anchors.left: parent.left
        fillMode: Image.PreserveAspectFit
        source: "image/board.png"

        Item {
            id: item1
            x: 224
            y: 16
            width: 2
            height: 3
        }

    }
}
