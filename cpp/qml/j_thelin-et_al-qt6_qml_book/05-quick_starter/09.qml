import QtQuick

Item {
    id: root
    
    width: 400; height: 400
    
    Image {
        x: 12; y: 12
        source: "img/triangle_red.png"
    }
    
    Image {
        x: 12 + 64 + 12; y: 12
        
        height: 72 / 2
        
        source: "img/triangle_red.png"
        
        fillMode: [
                    Image.Stretch, Image.PreserveAspectFit, Image.PreserveAspectCrop,
                    Image.Tile, Image.TileVertically, Image.TileHorizontally, Image.Pad
                  ][getRandomInt(0, 7)]
                  
        clip: (fillMode === Image.PreserveAspectCrop
            ? true
            : getRandomBool())
    }
    
    function getRandomInt(begin, end) {
        return Math.floor(Math.random() * (end - begin)) + begin;
    }
    
    function getRandomBool() { return Math.random() > 0.5; }  
}