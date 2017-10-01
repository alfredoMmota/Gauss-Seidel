#include "seidel.h"
#include "ui_seidel.h"
#include "math.h"
#include "cmath"//se incluye la libreria de matematica

seidel::seidel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::seidel)
{
    ui->setupUi(this);//se conectan los Botones de la interfaz a los Slots correspondientes
                      //the Interface Buttons are connected to the corresponding Slots
    connect(ui->calcular,SIGNAL(clicked()),this,SLOT(Metodo()));
    connect(ui->borrar,SIGNAL(clicked()),this,SLOT(Limpiar()));
    connect(ui->spinBox,SIGNAL(valueChanged(int)),this,SLOT(Habilitar()));//se connectan los spinbox de condicion de termino del Metodo
                                                                          //the term condition spinbox of the Method is connected
    connect(ui->doubleSpinBox,SIGNAL(valueChanged(double)),this,SLOT(Habilitar()));
}
seidel::~seidel()
{
    delete ui;
}
void seidel::Habilitar(){//se define lo que realizara la funcion Habilitar
                         //define what the Enable function will perform
    QString mensaje;//se crea la variable mensaje
                    //the message variable is created
    double operacion;//se declara la variable operacion
                     //the variable operation is declared
    double var1=ui->doubleSpinBox->value();//se obtienen los valores de los spin box de condicion
                                           //we obtain the values ​​of the condition spin box
    int var2=ui->spinBox->value();//y se guardan en 2 variables
                                  //and stored in 2 variables
    operacion=var1*var2;//se multiplica el contenido de los spin box
                        //the contents of the spin box are multiplied
    if(operacion!=0)//se revisa la condicion
                    //the condition is reviewed
        ui->calcular->setEnabled(true);//se habilita el boton Calcular
                                       //the Calculate button is enabled
    else
        mensaje.append("falta un ingresar el numero maximo ").append("\n de iteraciones o el error permitido");
    ui->Resultado->setText(mensaje);//si no se cumple la condicion se despliega el mensaje en la interfaz
                                    //if the condition is not fulfilled the message is displayed in the interface
}
void seidel::Metodo(){//se define lo que ara el metodo
                      //what the method will do
    QString resultado,valor1,valor2,valor3,valor4,valor5,error1,error2,error3,error4;
    double X1,X2,X3,X4,XRa,XRb,XRc,XRd,error,ea1,ea2,ea3,ea4;//se declaran variables tipo double y cadena para el metodo
                                                             //double and string variables are declared for the method
    a1=ui->a1->value();//se obtienen los valores de los spin box
                       //we obtain the values ​​of the spin box
    a2=ui->a2->value();
    a3=ui->a3->value();
    a4=ui->a4->value();
    b1=ui->b1->value();
    b2=ui->b2->value();
    b3=ui->b3->value();
    b4=ui->b4->value();
    c1=ui->c1->value();
    c2=ui->c2->value();
    c3=ui->c3->value();
    c4=ui->c4->value();
    d1=ui->d1->value();
    d2=ui->d2->value();
    d3=ui->d3->value();
    d4=ui->d4->value();
    A=ui->A->value();
    B=ui->B->value();
    C=ui->C->value();
    D=ui->D->value();
    int iteracion=0;//se inicializa la variable iteracion en 0
                    //the iteration variable is initialized to 0
    int iter=ui->spinBox->value();//se obtienen valores de los spinbox de condicion
                                  //we obtain values ​​of the condition spinbox
    error=ui->doubleSpinBox->value();
    X2=0,X3=0,X4=0;//se asignan valores iniciales a las X
                   //initial values ​​are assigned to X
    ea1=100.0,ea2=100.0,ea3=100.0,ea4=100.0;//se inicializa en 100 el error de cada X
                                            //the error of each X is initialized in 100
    while(((ea1>error)|(ea2>error)|(ea3>error)|(ea4>error))&(iteracion<iter)){//se crea la condicion con la cual se desarrollara el metodo
                                                                              //is created the condition with which the method will be developed
        if(iteracion>=1){//se verifica una segunda condicion
                         //there is a second condition
            XRa=X1;//se asignan valores absolutos para el calculo del error
                   //absolute values ​​are assigned for the calculation of the error
            XRb=X2;
            XRc=X3;
            XRd=X4;
        }
        X1=((A-(b1*X2)-(c1*X3)-(d1*X4))/a1);//se evalua las X con las ecuaciones
                                            //evaluate the X value with the equations
        X2=((B-(a2*X1)-(c2*X3)-(d2*X4))/b2);
        X3=((C-(a3*X1)-(b3*X2)-(d3*X4))/c3);
        X4=((D-(a4*X1)-(b4*X2)-(c4*X3))/d4);
        if(iteracion>=1){//se verifica una tercera condicion
                         //verify a third condition
        ea1=std::abs((X1-XRa)/X1);//se calcula el error nuevo de cada X
                                  //calculate the new error of each X
        XRa=X1;
        ea2=std::abs((X2-XRb)/X2);
        XRb=X2;
        ea3=std::abs((X3-XRc)/X3);
        XRc=X3;
        ea4=std::abs((X4-XRd)/X4);
        XRd=X4;
        }
        iteracion=iteracion+1;//iteracion aumenta 1
                              //add 1 iteration
    }
    //se guarda el mensaje en la variable resultado
    //saves message on the result variable
    resultado.append("El Valor de las X es el siguiente")
            .append("\n X1= ").append(valor1.setNum(X1)).append(" con un error de ").append(error1.setNum(ea1))
            .append("\n X2= ").append(valor2.setNum(X2)).append(" con un error de ").append(error2.setNum(ea2))
            .append("\n X3= ").append(valor3.setNum(X3)).append(" con un error de ").append(error3.setNum(ea3))
            .append("\n X4= ").append(valor4.setNum(X4)).append(" con un error de ").append(error4.setNum(ea4))
            .append("\nEn ").append(valor5.setNum(iteracion)).append(" Iteraciones");
    ui->Resultado->setText(resultado);//se despliega en pantalla
                                      //displays the result on screen
}
void seidel::Limpiar(){//se define la funcion Limpiar
                       // define the cleaning function
    ui->a1->setValue(0.00);//se modifican los spinbox a 0.0
                           // modify the spinbox with a 0.0 value
    ui->b1->setValue(0.00);
    ui->c1->setValue(0.00);
    ui->d1->setValue(0.00);
    ui->a2->setValue(0.00);
    ui->b2->setValue(0.00);
    ui->c2->setValue(0.00);
    ui->d2->setValue(0.00);
    ui->a3->setValue(0.00);
    ui->b3->setValue(0.00);
    ui->c3->setValue(0.00);
    ui->d3->setValue(0.00);
    ui->a4->setValue(0.00);
    ui->b4->setValue(0.00);
    ui->c4->setValue(0.00);
    ui->d4->setValue(0.00);
    ui->A->setValue(0.00);
    ui->B->setValue(0.00);
    ui->C->setValue(0.00);
    ui->D->setValue(0.00);
    ui->doubleSpinBox->setValue(0.0);
    ui->spinBox->setValue(0);
    ui->Resultado->clear();//se limpia el texto del label Resultado
                           //clean the text of the Result label
    ui->calcular->setEnabled(false);//se deshabilita el boton calcular
                                    //disable the calculate button
}
