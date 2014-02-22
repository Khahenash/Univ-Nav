#include "toolview.h"

ToolView::ToolView(QWidget * parent){
    this->setParent(parent);
    QVBoxLayout *layout = new QVBoxLayout(this);


    // ECHELLE
    QGroupBox *groupBox = new QGroupBox("Etape 1 : Echelle de la carte");
    groupBox->setStyleSheet ("QGroupBox{border: 2px solid gray;border-radius: 5px;margin-left:15px;}");

    QVBoxLayout *bv1 = new QVBoxLayout(this);
    QHBoxLayout *bh11 = new QHBoxLayout(this);
    QHBoxLayout *bh12 = new QHBoxLayout(this);

    QPushButton *button_echelle = new QPushButton("Definir");
    QLineEdit *line_echelle_val = new QLineEdit("");
    QLabel *label_metre = new QLabel("metres");

    bh12->addWidget(button_echelle);
    bh12->addWidget(line_echelle_val);
    bh12->addWidget(label_metre);
    bv1->addLayout(bh11);
    bv1->addLayout(bh12);
    bv1->addWidget(new QLabel("Aide : Cliquez sur 'Definir' pour commencer.\n  Sur la carte, cliquez a gauche puis a droite de\n  l'echelle du plan puis saisissez la valeur en metres."));

    groupBox->setLayout(bv1);

    layout->addWidget(groupBox);



    // ACCES
    QGroupBox *groupBox2 = new QGroupBox("Etape 2 : Acces du niveau");
    groupBox2->setStyleSheet ("QGroupBox{border: 2px solid gray;border-radius: 5px;margin-left:15px;}");

    QVBoxLayout *bv2 = new QVBoxLayout(this);
    QHBoxLayout *bh21 = new QHBoxLayout(this);
    QHBoxLayout *bh22 = new QHBoxLayout(this);

    QPushButton *button_escalier = new QPushButton("Escalier");
    QPushButton *button_ascenseur = new QPushButton("Ascenseur");
    QPushButton *button_porte = new QPushButton("Porte");
    QPushButton *button_qr_code = new QPushButton("QR Code");
    bh22->addWidget(button_escalier);
    bh22->addWidget(button_ascenseur);
    bh22->addWidget(button_porte);
    bh22->addWidget(button_qr_code);

    QComboBox *combo_acces = new QComboBox;
    combo_acces->addItem(tr("test 1"));
    combo_acces->addItem(tr("test 2"));
    bh21->addWidget(combo_acces);

    bv2->addWidget(new QLabel("\nAcces Existant : "));
    bv2->addLayout(bh21);
    bv2->addWidget(new QLabel("Nouvel Acces : "));
    bv2->addLayout(bh22);
    groupBox2->setLayout(bv2);

    layout->addWidget(groupBox2);

    // COULOIRS
    QGroupBox *groupBox3 = new QGroupBox("Etape 3 : Creation des couloirs");
    groupBox3->setStyleSheet ("QGroupBox{border: 2px solid gray;border-radius: 5px;margin-left:15px;}");

    QVBoxLayout *bv3 = new QVBoxLayout(this);
    QHBoxLayout *bh31 = new QHBoxLayout(this);
    QHBoxLayout *bh32 = new QHBoxLayout(this);

    bv3->addWidget(new QLabel("Aide : Cliquez sur l'un des acces present sur\n  la carte pour commencer. Relier les acces\n  afin de definir l'ensemble des couloirs.\n  Dans le cas d'un virage, faites un clic gauche\n  pour changer de direction.  "));

    groupBox3->setLayout(bv3);
    layout->addWidget(groupBox3);

    // SALLES
    QGroupBox *groupBox4 = new QGroupBox("Etape 4 : Creation des salles");
    groupBox4->setStyleSheet ("QGroupBox{border: 2px solid gray;border-radius: 5px;margin-left:15px;}");

    QVBoxLayout *bv4 = new QVBoxLayout(this);
    QHBoxLayout *bh41 = new QHBoxLayout(this);
    QHBoxLayout *bh42 = new QHBoxLayout(this);
    QHBoxLayout *bh43 = new QHBoxLayout(this);
    QHBoxLayout *bh44 = new QHBoxLayout(this);


    QLineEdit *line_code_admin = new QLineEdit("Code admin");
    QLineEdit *line_code_salle = new QLineEdit("Nom d'usage");
    QPushButton *button_new_salle = new QPushButton("Creer");
    bh41->addWidget(new QLabel("\nNouvelle salle : "));
    bh42->addWidget(line_code_admin);
    bh42->addWidget(line_code_salle);
    bh42->addWidget(button_new_salle);
    bh43->addWidget(new QLabel("Positionner une salle : "));
    QComboBox *combo_salle = new QComboBox();
    QPushButton *button_add_salle = new QPushButton("Positionner");
    combo_salle->addItem(tr("Salle I019"));
    bh44->addWidget(combo_salle);
    bh44->addWidget(button_add_salle);


    bv4->addLayout(bh41);
    bv4->addLayout(bh42);
    bv4->addLayout(bh43);
    bv4->addLayout(bh44);

    groupBox4->setLayout(bv4);
    //groupBox4->setMaximumHeight(20);
    layout->addWidget(groupBox4);

    // options
    QGroupBox *groupBox5 = new QGroupBox;
    groupBox5->setStyleSheet ("QGroupBox{border: 2px solid gray;border-radius: 5px;margin-left:15px;}");

    QVBoxLayout *bv5 = new QVBoxLayout(this);
    QHBoxLayout *bh51 = new QHBoxLayout(this);
    QHBoxLayout *bh52 = new QHBoxLayout(this);

    correct_xy = new QCheckBox("Correction de trajectoire");
    correct_xy->setChecked(true);
    bh51->addWidget(correct_xy);
    bv5->addLayout(bh51);

    groupBox5->setLayout(bv5);
    groupBox5->setMaximumHeight(40);
    layout->addWidget(groupBox5);
}
