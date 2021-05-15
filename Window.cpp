#include "Window.h"

/**
 * @file Window.cpp
 * @authors Diabloget, Jjvv21
 */

/**
 * @class Window
 * @brief Permite instanciar la ventana.
 * @details Contiene todas las caracteristicas de la ventana del IDE para la ejecucion y escritura de codigo C!.
 */

/**
 * @brief Constructor de la ventana.
 * @param parent
 * @details Constructor de la interfaz grafica usando biblioteca QT.
 */
Window::Window(QWidget *parent) :
        QWidget(parent) {
    setFixedSize(1100, 650);
    this->setWindowTitle("C! IDE");
    QGridLayout *layout = new QGridLayout(this);
    this->setLayout(layout);
    /***
     * @Widget
     * Estos son los botones que se utilizaran en el IDE
     */
    //BOTON PARA EJECUTAR EL CODIGO
    RunButton = new QPushButton("▶",this);
    RunButton->setFixedSize(30,30);
    connect(RunButton,SIGNAL(clicked()),this,SLOT(RunProgram()));
    //BOTON PARA DETENER EL FLUJO DEL PROGRAMA
    StopButton = new QPushButton("▪",this);
    StopButton->setFixedSize(32,32);
    connect(StopButton,SIGNAL(clicked()),this,SLOT(StopProgram()));
    //BOTON PARA SALTAR LINEA
    NextLineButton = new QPushButton("▼",this);
    NextLineButton->setFixedSize(30,30);
    connect(NextLineButton,SIGNAL(clicked()),this,SLOT(NextLine()));
    /***
     * @Layout
     * LayOut para los botones
     */
    layout->addWidget(NextLineButton,0,1);
    layout->addWidget(RunButton, 0, 0);
    layout->addWidget(StopButton, 0, 2);
    /***
     * @Widget
     * Este es un grupo en el que se crea dentro una contenedora para el TextEdit
     */
    QGroupBox *box = new QGroupBox("Code C!:", this);
    QVBoxLayout *boxLayout = new QVBoxLayout(box);
    QWidget* CodeWindow = new QWidget(box);
    CodeWindow->setFixedHeight(400);
    boxLayout->addWidget(CodeWindow);
    layout->addWidget(box, 1, 2);
    /***
     * @Widget
     * Esta es la tabla con las columnas para el RAM LIVE VIEW
     */
    Table = new QTableWidget(this);
    Table->setFixedSize(200,500);
    Table->setColumnCount(4);
    /***
     * @Headers
     * Estas son las cabeceras para cada columna
     */
    Header1 = new QTableWidgetItem();
    Header2 = new QTableWidgetItem();
    Header3 = new QTableWidgetItem();
    Header4 = new QTableWidgetItem();
    Header1->setText("Valor");
    Header2->setText("Direccion");
    Header3->setText("Etiqueta");
    Header4->setText("Conteo");
    Table->setHorizontalHeaderItem(0,Header1);
    Table->setHorizontalHeaderItem(1,Header2);
    Table->setHorizontalHeaderItem(2,Header3);
    Table->setHorizontalHeaderItem(3,Header4);
    Table->setRowCount(15);
    layout->addWidget(Table,1,3);

    QGroupBox *LogBox = new QGroupBox("Registro de consola", this);
    QVBoxLayout *LogLayout = new QVBoxLayout(LogBox);
    QWidget* LogWindow = new QWidget(LogBox);
    CodeWindow->setFixedHeight(350);
    LogLayout->addWidget(LogWindow);
    layout->addWidget(LogBox, 2, 2);

    QHBoxLayout *nameLayout = new QHBoxLayout(CodeWindow);
    Code = new QTextEdit();
    Code->setFont(
            QFont ("Ubuntu Mono", 12)
    );
    nameLayout->addWidget(Code);


    QHBoxLayout *BoxLogLayout = new QHBoxLayout(LogWindow);
    QTabWidget *TabWindow = new QTabWidget();
    BoxLogLayout->addWidget(TabWindow);
    Log1 = new QTextEdit(this);
    Log1->setFixedHeight(100);
    Log2 = new QTextEdit(this);
    Log2->setFixedHeight(100);
    TabWindow->addTab(Log1, tr("Stdout"));
    TabWindow->addTab(Log2, tr("Application Log"));
}

/**
 * @brief Inicia la escritura.
 * @details Instancia a Lexer, para escribir lo escrito en el IDE dentro de un archivo de texto y tokenizarlo.
 */
void Window::RunProgram(){
    //Log1 = Printer().Log1;
    lexito = Lexer();
    vecIndex = 0;
    QString data = Window::Code->toPlainText();
    const QString &s = data;
    qDebug("%s", qPrintable(s));
    //std::cout << s.toStdString() <<"\n";
    lexito.write("test.c!", s.toStdString());
    lexito.lex("test.c!");
}
void Window::StopProgram() {
    std::cout<<"Stop";
}
/**
 * @details Agrega al vector cada instruccion por la que avanza dentro del texto.
 * @brief Avanza una linea en el texto.
 */
void Window::NextLine() {
    //el metodo de abajo se trae el string de memoria.
    vectorAdder(lexito.decomposer.readLine(vecIndex));
    Increment();
    //Lexer().server.startServer();
    std::cout<<"Siguiente\n";
}

/**
 * @brief Incrementa el index.
 * @details Incrementa el index del vector.
 */
void Window::Increment() {
    vecIndex++;
}

/**
 * @brief Agrega al vector el objeto de memoria.
 * @param string Json
 * @details Usando la clase MemoryObject, descompone el Json entrante en un objeto de esta clase y lo agrega al vector.
 */
void Window::vectorAdder(std::string Json){
    lexito.setPrintText("Json Received: " + Json + "\n");
    //de aqui hasta Json = json es un submetodo conocido como Don Krikon.
    /*
    string json;
    int p = 0;
    while(Json[p]!='}'){
        json.push_back(Json[p]);
        p++;
    }
    json.push_back('}');
    Json = json;
     */

    QByteArray byteArray(Json.c_str(), Json.length());
    QJsonDocument doc(QJsonDocument::fromJson(byteArray));
    QJsonObject qjson = doc.object();
    //std::cout << qjson.value("mdirec").toInt() << "\n";
    if(qjson.contains("mdirec")){
        std::string mdirec = std::to_string(qjson.value("mdirec").toInt());
        std::string name = qjson.value("name").toString().toStdString();
        std::string value = qjson.value("value").toString().toStdString();
        std::string scope = to_string(qjson.value("scope").toInt());

        if(memObjVector.size()!=0){
            if(memObjVector[memObjVector.size()-1].scope > scope){
                vector<MemoryObject> temp = vector<MemoryObject>();
                for(int i = 0; i<memObjVector.size()-1;i++){
                    if(memObjVector[i].scope <= scope){
                        temp.push_back(memObjVector[i]);
                    }
                }
                memObjVector = temp;
            }
        }
        memObjVector.push_back(MemoryObject(mdirec, name, value, "N/D", scope));

    }
    checkScope();
    printOnConsole();
    //updateRamViewer();

}

/**
 * @brief Verifica el scope
 * @details Verifica el scope para ver si es necesario actualizar el LiveRamViewer.
 */
void Window::checkScope(){
    std::vector<MemoryObject> tempvector = std::vector<MemoryObject>();
    for(int i = 0; i<memObjVector.size();i++){
        if(memObjVector[i].scope<=memObjVector[memObjVector.size()-1].scope){
            tempvector.push_back(memObjVector[i]);
        }
    }
    //lexito.memObjVector = tempvector;
    //Printer().setMemVector(tempvector);
    //lexito.setPrintVector(tempvector);
    memObjVector = tempvector;
    updateRamViewer();
}

/**
 * @brief set del texto en el Log
 * @details Lee la string que contiene los logs para agregarlos a la interfaz.
 */
void Window::printOnConsole(){
    Log2->setText(QString::fromStdString(lexito.getPrintText()));
    //Log1->setText(QString::fromStdString(lexito.getPrintText2()));
}

/**
 * @brief Actualiza al LiveRamViewer
 * @details Haciendo uso del vector con objetos de memoria, actualiza cada una de las filas y columnas del LiveRamViewer con la memoria actual.
 */
void Window::updateRamViewer(){
    lexito.setPrintText("Updating LiveRamViewer");
    for(int i = 0; i<memObjVector.size();i++){
        int m = 0;
        while(m<4){
            if(m==0){
                Table->setItem(i, m, new QTableWidgetItem(QString::fromStdString(memObjVector[i].value)));
            }
            if(m==1){
                Table->setItem(i, m, new QTableWidgetItem(QString::fromStdString(memObjVector[i].memDirect)));
            }
            if(m==2){
                Table->setItem(i, m, new QTableWidgetItem(QString::fromStdString(memObjVector[i].name)));
            }
            if(m==3){
                Table->setItem(i, m, new QTableWidgetItem(QString::fromStdString(memObjVector[i].constant)));
            }
            m++;
        }
        m=0;
        //Table->setItem(x, y, new QTableWidgetItem());
    }
}