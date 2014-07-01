import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Dialogs 1.1
import QtQuick.Layouts 1.1
import com.testTask.threshholding 1.0

ApplicationWindow {
    id: applicationWindow
    visible: true
    width: 640
    height: 480
    minimumWidth: rowLayout.implicitWidth
    minimumHeight: 320
    title: qsTr("Probeaufgabe")

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")

            MenuItem {
                text: "File Open ..."
                onTriggered: fileLoader.open()
            }

            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    Image {
        id: image
        objectName: "test"

        anchors.fill: parent
        anchors.bottomMargin: rowLayout.height
        anchors.bottom: rowLayout.top
        fillMode: Image.PreserveAspectFit
        source: "image://threshholdingImage/" + textField.text
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
    }

    ImageProvider {
        source: fileLoader.fileUrl
    }
}
