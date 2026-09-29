import QtQuick

Image {
    id: root
    source: "img/background.png"

    Image {
        id: pole
        
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        
        source: "img/pole.png"
    }

    Image {
        id: wheel

        anchors.centerIn: parent

        source: "img/pinwheel.png"

        Behavior on rotation {
            NumberAnimation {
                duration: 250
            }
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: wheel.rotation += 90
    }
}
