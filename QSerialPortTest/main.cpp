
#include <QtCore/QCoreApplication>
#include <QSerialPort>
#include <qtextstream.h>

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	QTextStream cin(stdin);
	QTextStream cout(stdout);

	QSerialPort qsp;
	qsp.setPortName("COM3");
	qsp.setBaudRate(115200);
	qsp.setParity(QSerialPort::Parity::NoParity);
	qsp.setDataBits(QSerialPort::DataBits::Data8);
	qsp.setStopBits(QSerialPort::StopBits::OneStop);
	qsp.open(QIODevice::ReadWrite);

	QString message = "\nset TurnerPulseHalfPeriod %1\n";
	message = message.arg(100);


	qsp.write(message.toLocal8Bit());
	qsp.flush();
	qsp.waitForBytesWritten(1000);

	qsp.waitForReadyRead(1000);
	QByteArray readBytes = qsp.readAll();


	cout << "Read back: " << readBytes << endl;
	getchar();
}
