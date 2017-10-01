#ifndef SEIDEL_H
#define SEIDEL_H

#include <QMainWindow>

namespace Ui {
class seidel;
}
class seidel : public QMainWindow
{
    Q_OBJECT
public:
    explicit seidel(QWidget *parent = 0);
    ~seidel();
    double a1,a2,a3,a4,b1,b2,b3,b4,c1,c2,c3,c4,d1,d2,d3,d4,A,B,C,D;//se crean las variables para obtener los valores de los spinbox
                                                                   //the variables are created to obtain the values ​​of the spinbox
private slots:
    void Metodo();//se declara la funcion Metodo
                  //function is declared Method
    void Habilitar();//se declara la funcion Habilitar
                     //the Enable function is declared
    void Limpiar();//se declara la funcion Limpiar
                   //the Clean function is declared
private:
    Ui::seidel *ui;
};
#endif // SEIDEL_H
