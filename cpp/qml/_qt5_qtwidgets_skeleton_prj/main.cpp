#include <QtWidgets>
#include <QLabel>

int main(int argc, char** argv) {
    QApplication app{ argc, argv };
    
    QLabel label{ "e.g." };
    label.show();

    return app.exec();
}
