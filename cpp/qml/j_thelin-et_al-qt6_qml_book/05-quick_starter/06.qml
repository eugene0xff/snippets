import QtQuick

Item {
    id: root
    
    width: 400; height: 400
    
    Rectangle {
        id: rect1
        
        x: 12; y: 12
        width: 176; height: 96
        
        gradient: Gradient {
            GradientStop { position: 0.0; color: "lightsteelblue" }
            GradientStop { position: 1.0; color: "slategray" }
        }
        
        border.color: "slategray"
    }
    
}