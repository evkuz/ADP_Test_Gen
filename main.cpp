#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QDataStream>

#include <iostream>
#include <conio.h>


#include <qt_windows.h>
#include <windows.h>



#define def_file "ADP_data_000.bin"

#define N_number 23
//#define bin_path  "d:/QT-Projects/Camac_USB/Backup/bin/"

//#define bin_path "./" //d:/QT-Projects/Camac_USB/KK_Tab_14/release/
//#define repaired_path "./" //d:/QT-Projects/Camac_USB/KK_Tab_14/release/
//#define f_path "d:\QT-Projects\Camac_USB\ADP_Test_Gen"



void File_Open(QString filename);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString str, fname, fstr, fstr_repaired;
    QFile mfile, repaired_file;
    QByteArray ba;
    quint64 i, j,  data, fsize, bytes_to_write, result;
    uchar num;
    char fdata;
    QStringList file_list;

    BOOL fopen, End_Of_File_Flag;

    const char  dataSet[8] = {0xf0, 0x11, 0x00, 0x07, 0xD0, 0x00, 0x00, 0x80}; ; //= new char[8];

    End_Of_File_Flag = TRUE;


    fname = def_file;
    mfile.setFileName(fname);

    if (!mfile.open(QIODevice::ReadWrite | QIODevice::Truncate )) { qDebug() <<  "The file " <<  mfile.fileName() << " does not exist !";  return 0;}
    qDebug() << "Current file name is " << mfile.fileName();

    j =0; num=1;

while (num <= N_number)
{

 // if (!mfile.seek(j)) qDebug() <<  "Seek operation ERROR in string 146 " << "J value is " << j;
  //mfile.read(&fdata, 8);
  mfile.write(dataSet, 8);


num++; //1 порцию обработали. Двигаемся дальше по файлу
//if (!mfile.seek(j))  qDebug() <<  "Seek operation ERROR in string 186 " << "J value is " << j;

}//while (!mfile.atEnd())

mfile.close();

qDebug() << "Done";
    return a.exec();
}
