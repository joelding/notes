#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	//QLabel *label = new QLabel("Hello! World!");
	QLabel *label = new QLabel("<h1><font color=blue>Hello!</font><font color=red> World!</font></h1>");
	label->setWindowTitle("First Qt!");
	label->resize(200, 50);
	label->show();

	return app.exec();
}
