import QtQuick

Rectangle {
    id: root

    width: 400; height: 200

    Text {
        id: thisLabel

        property int times: 24

        width: root.width
        height: root.height / 4
        horizontalAlignment: Text.AlignHCenter

        font.family: "Ubuntu"
        font.pixelSize: 24

        onHeightChanged: console.log("height:", height)

        KeyNavigation.tab: otherLabel
        focus: true
        color: focus ? "red" : "black"

        text: "thisLabel: Greetings " + times
    }
    
    Text {
        id: otherLabel

        y: thisLabel.y + thisLabel.height + 10

        width: root.width
        horizontalAlignment: Text.AlignHCenter

        KeyNavigation.tab: thisLabel
        focus: false
        color: focus ? "red" : "black"

        text: "otherLabel"
    }
}