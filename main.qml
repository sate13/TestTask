import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Dialogs 1.1
import QtQuick.Layouts 1.1

ApplicationWindow {
    id: applicationWindow
    visible: true
    width: 640
    height: 480
    minimumWidth: rowLayout.implicitWidth
    minimumHeight: 320
    title: "Probeaufgabe"

    menuBar: MenuBar {
        Menu {
            title: "File"

            MenuItem {
                text: "File Open ..."
                onTriggered: fileLoader.open()
            }

            MenuItem {
                text: "Exit"
                onTriggered: Qt.quit();
            }
        }
    }

    Image {
        id: image

        anchors.fill: parent
        anchors.bottomMargin: rowLayout.height
        anchors.bottom: rowLayout.top
        fillMode: Image.PreserveAspectFit
        source: if (checkBox.checked) { fileLoader.fileUrl }
                else { "image://threshholdingImage/" + fileLoader.fileUrl + ":*:" + textField.text }
    }

    RowLayout {
        id: rowLayout

        anchors.top: image.bottom
        width: parent.width

        TextField {
            id: textField

            inputMask: "999"
            readOnly: true
            implicitWidth: 30
            text: slider.value
        }

        Slider {
            id: slider

            Layout.fillWidth: true
            implicitWidth: 320
            minimumValue: 0
            maximumValue: 255
            stepSize: 1
            enabled: if (checkBox.checked) { false }
                     else { true }
        }
        
        CheckBox {
            id: checkBox
            text: "Original"
            checked: true
        }
    }    

    statusBar: StatusBar {
        Label {
            text: fileLoader.fileUrl
            elide: Text.ElideMiddle
        }
    }

    FileDialog {
        id: fileLoader
        onFileUrlChanged: {
            checkBox.checked = true
            slider.value = 0
        }
    }
}


