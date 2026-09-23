import QtQuick

Item {
    id: root
    
    width: 400; height: 400
    
    Text {
        width: 40; height: 120
        text: "A very long text"
        
        elide: [Text.ElideNone, Text.ElideLeft, Text.ElideMiddle, Text.ElideRight][getRandomInt(0, 4)]
        style: [Text.Normal, Text.Outline, Text.Raised, Text.Sunken][getRandomInt(0, 4)]
        styleColor: "#ff4444"
        horizontalAlignment: [Text.AlignLeft, Text.AlignRight, Text.AlignHCenter, Text.AlignJustify][getRandomInt(0, 4)]
        verticalAlignment: [Text.AlignTop, Text.AlignVCenter, Text.AlignBottom][getRandomInt(0, 3)]
        
        wrapMode: (Text.ElideNone == elide
            ? [Text.NoWrap, Text.WordWrap, Text.WrapAnywhere, Text.Wrap][getRandomInt(0, 4)]
            : Text.NoWrap)
    }
    
    function getRandomInt(min, max) {
        return Math.floor(Math.random() * (max - min)) + min;
    }
}