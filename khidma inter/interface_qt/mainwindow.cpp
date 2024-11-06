#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QMessageBox>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix("C:/Users/GIGABYTE/Desktop/khidma inter/interface_qt/img/Nouveau dossier/aze.png");
    ui->pic1->setPixmap(pix);
    QPixmap pix2("C:/Users/GIGABYTE/Desktop/khidma inter/interface_qt/img/Nouveau dossier/stt.png");
    ui->label_64->setPixmap(pix2);
    QPixmap pix3("C:/Users/GIGABYTE/Desktop/khidma inter/interface_qt/img/Nouveau dossier/avc.png");
    ui->label_71->setPixmap(pix3);
    QPixmap pix4("C:/Users/GIGABYTE/Desktop/khidma inter/interface_qt/img/Nouveau dossier/stat.png");
    ui->label_30->setPixmap(pix4);
    //QPixmap pix5("C:/Users/GIGABYTE/Desktop/khidma inter/interface_qt/img/Nouveau dossier/stat.png");
   // ui->label_3->setPixmap(pix5);
    QPixmap pix6("C:/Users/GIGABYTE/Desktop/khidma inter/interface_qt/img/Nouveau dossier/mariem.jpeg");
    ui->label_56->setPixmap(pix6);
    QPixmap pix7("C:/Users/GIGABYTE/Desktop/khidma inter/interface_qt/img/Nouveau dossier/mariem1.jpeg");
    ui->label_62->setPixmap(pix7);
    QPixmap pix8("C:/Users/GIGABYTE/Desktop/khidma inter/interface_qt/img/Nouveau dossier/siwar.jpeg");
    ui->label_35->setPixmap(pix8);
    QPixmap pix9("C:/Users/GIGABYTE/Desktop/khidma inter/interface_qt/img/Nouveau dossier/hazem.jpeg");
    ui->label_34->setPixmap(pix9);

    // Initialize the stacked widget
    stackedWidget = findChild<QStackedWidget*>("stackedWidget");

    // Connect ajoutemp button to its slot
    connect(ui->pushButton_8, &QPushButton::clicked, this, &MainWindow::on_pushButton_8_clicked);

    // Connect salary button to its slot
    connect(ui->pushButton_10, &QPushButton::clicked, this, &MainWindow::on_pushButton_10_clicked);
    connect(ui->pushButton_12, &QPushButton::clicked, this, &MainWindow::on_pushButton_12_clicked);
    connect(ui->pushButton_14, &QPushButton::clicked, this, &MainWindow::on_pushButton_14_clicked);
    connect(ui->pushButton_35, &QPushButton::clicked, this, &MainWindow::on_pushButton_35_clicked);
    connect(ui->pushButton_36, &QPushButton::clicked, this, &MainWindow::on_pushButton_36_clicked);
    connect(ui->pushButton_37, &QPushButton::clicked, this, &MainWindow::on_pushButton_37_clicked);
    connect(ui->pushButton_28, &QPushButton::clicked, this, &MainWindow::on_pushButton_28_clicked);
    connect(ui->pushButton_27, &QPushButton::clicked, this, &MainWindow::on_pushButton_27_clicked);
    connect(ui->pushButton_25, &QPushButton::clicked, this, &MainWindow::on_pushButton_25_clicked);
    connect(ui->pushButton_24, &QPushButton::clicked, this, &MainWindow::on_pushButton_24_clicked);

    // Connect add button to slot
    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::on_addButton_clicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}

// Slot for ajoutemp button (pushButton_8)
void MainWindow::on_pushButton_8_clicked() {
    stackedWidget->setCurrentIndex(1);  // Assuming 'a1' is the second page (index 1)
}

// Slot for salary button (pushButton_10)
void MainWindow::on_pushButton_10_clicked() {
    stackedWidget->setCurrentIndex(5);  // Assuming 'a1_1' is the third page (index 2)
}

void MainWindow::on_pushButton_12_clicked() {
    stackedWidget->setCurrentIndex(11);  // Assuming 'a1_1' is the third page (index 2)
}

void MainWindow::on_pushButton_14_clicked() {
    stackedWidget->setCurrentIndex(8);  // Assuming 'a1_1' is the third page (index 2)
}

void MainWindow::on_pushButton_35_clicked() {
    stackedWidget->setCurrentIndex(9);  // Assuming 'a1_1' is the third page (index 2)
}

void MainWindow::on_pushButton_36_clicked() {
    stackedWidget->setCurrentIndex(10);  // Assuming 'a1_1' is the third page (index 2)
}

void MainWindow::on_pushButton_37_clicked() {
    stackedWidget->setCurrentIndex(2);  // Assuming 'a1_1' is the third page (index 2)
}

void MainWindow::on_pushButton_28_clicked() {
    stackedWidget->setCurrentIndex(0);  // Assuming 'a1_1' is the third page (index 2)
}

void MainWindow::on_pushButton_27_clicked() {
    stackedWidget->setCurrentIndex(7);  // Assuming 'a1_1' is the third page (index 2)
}

void MainWindow::on_pushButton_25_clicked() {
    stackedWidget->setCurrentIndex(3);  // Assuming 'a1_1' is the third page (index 2)
}

void MainWindow::on_pushButton_24_clicked() {
    stackedWidget->setCurrentIndex(4);  // Assuming 'a1_1' is the third page (index 2)
}









void MainWindow::on_modifyButton_clicked() {
    // Collect data from modification fields
    QString id = ui->lineEdit_120->text();

    // Check if ID is empty
    if (id.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "ID must not be empty.");
        return;
    }

    // Check if the ID exists in the table
    bool found = false;
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        QTableWidgetItem *item = ui->tableWidget->item(row, 2); // Assuming ID is in the 3rd column (index 2)
        if (item && item->text() == id) {
            found = true;

            // Modify only the fields that are filled in
            if (!ui->lineEdit_119->text().isEmpty()) {  // Login
                ui->tableWidget->setItem(row, 0, new QTableWidgetItem(ui->lineEdit_119->text()));
            }

            if (!ui->lineEdit_125->text().isEmpty()) {  // Password
                ui->tableWidget->setItem(row, 1, new QTableWidgetItem(ui->lineEdit_125->text()));
            }

            if (!ui->lineEdit_126->text().isEmpty()) {  // CIN
                ui->tableWidget->setItem(row, 3, new QTableWidgetItem(ui->lineEdit_126->text()));
            }

            if (!ui->lineEdit_121->text().isEmpty()) {  // First Name
                QString firstName = ui->lineEdit_121->text().trimmed();
                if (!QRegularExpression("^[A-Za-z ]+$").match(firstName).hasMatch()) {
                    QMessageBox::warning(this, "Input Error", "First Name must be alphabetic.");
                    return;
                }
                ui->tableWidget->setItem(row, 4, new QTableWidgetItem(firstName));
            }

            if (!ui->lineEdit_127->text().isEmpty()) {  // Last Name
                QString lastName = ui->lineEdit_127->text().trimmed();
                if (!QRegularExpression("^[A-Za-z ]+$").match(lastName).hasMatch()) {
                    QMessageBox::warning(this, "Input Error", "Last Name must be alphabetic.");
                    return;
                }
                ui->tableWidget->setItem(row, 5, new QTableWidgetItem(lastName));
            }

            if (!ui->lineEdit_122->text().isEmpty()) {  // Email
                QString email = ui->lineEdit_122->text().trimmed();
                QRegularExpression emailRegex("^[\\w.-]+@[\\w.-]+\\.[a-zA-Z]{2,}$");
                if (!emailRegex.match(email).hasMatch()) {
                    QMessageBox::warning(this, "Input Error", "Please enter a valid email address.");
                    return;
                }
                ui->tableWidget->setItem(row, 6, new QTableWidgetItem(email));
            }

            if (!ui->comboBox_18->currentText().isEmpty()) {  // Role
                ui->tableWidget->setItem(row, 7, new QTableWidgetItem(ui->comboBox_18->currentText()));
            }

            if (!ui->lineEdit_123->text().isEmpty()) {  // Phone
                QString phone = ui->lineEdit_123->text().trimmed();
                QRegularExpression phoneRegex("^\\d{10}$");
                if (!phoneRegex.match(phone).hasMatch()) {
                    QMessageBox::warning(this, "Input Error", "Please enter a valid 10-digit phone number.");
                    return;
                }
                ui->tableWidget->setItem(row, 8, new QTableWidgetItem(phone));
            }

            if (ui->radioButton_23->isChecked() || ui->radioButton_24->isChecked()) {  // Gender
                QString gender = ui->radioButton_23->isChecked() ? "Male" : "Female";
                ui->tableWidget->setItem(row, 9, new QTableWidgetItem(gender));
            }

            if (!ui->lineEdit_124->text().isEmpty()) {  // Salary
                QString salary = ui->lineEdit_124->text().trimmed();
                bool salaryIsValid;
                double salaryValue = salary.toDouble(&salaryIsValid);
                if (!salaryIsValid || salaryValue <= 0) {
                    QMessageBox::warning(this, "Input Error", "Please enter a valid positive number for salary.");
                    return;
                }
                ui->tableWidget->setItem(row, 10, new QTableWidgetItem(salary));
            }

            if (!ui->dateEdit_25->date().isNull()) {  // Date of Birth
                ui->tableWidget->setItem(row, 11, new QTableWidgetItem(ui->dateEdit_25->date().toString("dd/MM/yyyy")));
            }

            if (!ui->dateEdit_26->date().isNull()) {  // Hire Date
                ui->tableWidget->setItem(row, 12, new QTableWidgetItem(ui->dateEdit_26->date().toString("dd/MM/yyyy")));
            }

            QMessageBox::information(this, "Modification", "Employee details updated successfully.");
            break;
        }
    }

    if (!found) {
        QMessageBox::warning(this, "Modification", "ID not found. Please enter a valid ID.");
    }
}










// Slot for Add Button to insert data into the table widget
void MainWindow::on_addButton_clicked() {
    // Collect data from input fields
    QString login = ui->lineEdit_17->text().trimmed();
    QString password = ui->lineEdit_18->text().trimmed();
    QString id = ui->lineEdit_16->text().trimmed();
    QString cin = ui->lineEdit_19->text().trimmed();
    QString firstName = ui->lineEdit_20->text().trimmed();
    QString lastName = ui->lineEdit_40->text().trimmed();
    QString email = ui->lineEdit_21->text().trimmed();
    QString role = ui->comboBox->currentText();
    QString phone = ui->lineEdit_22->text().trimmed();

    // Check gender based on radio buttons
    QString gender;
    if (ui->radioButton->isChecked()) {
        gender = "Male";
    } else if (ui->radioButton_2->isChecked()) {
        gender = "Female";
    } else {
        gender = "Unknown"; // Handle case where no gender is selected
    }

    QString salary = ui->lineEdit_39->text().trimmed();
    QString dob = ui->dateEdit->date().toString("dd/MM/yyyy");
    QString hireDate = ui->dateEdit_2->date().toString("dd/MM/yyyy");

    // Validate input fields
    if (login.isEmpty() || password.isEmpty() || id.isEmpty() || cin.isEmpty() ||
        firstName.isEmpty() || lastName.isEmpty() || email.isEmpty() ||
        phone.isEmpty() || salary.isEmpty()) {

        QMessageBox::warning(this, "Input Error", "All fields must be filled.");
        return;
    }

    // Check email format
    QRegularExpression emailRegex(R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$)");
    if (!emailRegex.match(email).hasMatch()) {
        QMessageBox::warning(this, "Input Error", "Please enter a valid email address.");
        return;
    }

    // Check phone format (assuming a 10-digit phone number, modify as needed)
    QRegularExpression phoneRegex("^\\d{10}$");
    if (!phoneRegex.match(phone).hasMatch()) {
        QMessageBox::warning(this, "Input Error", "Please enter a valid 10-digit phone number.");
        return;
    }

    // Check salary format (numeric)
    bool salaryOk;
    salary.toDouble(&salaryOk);
    if (!salaryOk || salary.toDouble() <= 0) {
        QMessageBox::warning(this, "Input Error", "Please enter a valid salary amount.");
        return;
    }

    // Check if ID and CIN are numeric
    bool idOk, cinOk;
    id.toInt(&idOk);
    cin.toInt(&cinOk);
    if (!idOk || !cinOk) {
        QMessageBox::warning(this, "Input Error", "ID and CIN must be numeric values.");
        return;
    }

    // If all validations pass, insert data into the table
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);

    // Insert data into the table widget
    ui->tableWidget->setItem(row, 0, new QTableWidgetItem(login));
    ui->tableWidget->setItem(row, 1, new QTableWidgetItem(password));
    ui->tableWidget->setItem(row, 2, new QTableWidgetItem(id));
    ui->tableWidget->setItem(row, 3, new QTableWidgetItem(cin));
    ui->tableWidget->setItem(row, 4, new QTableWidgetItem(firstName));
    ui->tableWidget->setItem(row, 5, new QTableWidgetItem(lastName));
    ui->tableWidget->setItem(row, 6, new QTableWidgetItem(email));
    ui->tableWidget->setItem(row, 7, new QTableWidgetItem(role));
    ui->tableWidget->setItem(row, 8, new QTableWidgetItem(phone));
    ui->tableWidget->setItem(row, 9, new QTableWidgetItem(gender));
    ui->tableWidget->setItem(row, 10, new QTableWidgetItem(salary));
    ui->tableWidget->setItem(row, 11, new QTableWidgetItem(dob));
    ui->tableWidget->setItem(row, 12, new QTableWidgetItem(hireDate));

    // Display success message
    QMessageBox::information(this, "Success", "Data added successfully!");
}






void MainWindow::on_deleteButton_clicked() {
    QString idToDelete = ui->lineEdit_128->text().trimmed(); // Using lineEdit_128 for ID input

    // Check if ID input is empty
    if (idToDelete.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter an ID to delete.");
        return;
    }

    // Search for the row with the matching ID
    bool found = false;
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        QTableWidgetItem *item = ui->tableWidget->item(row, 2); // Assuming the ID is in the third column (index 2)

        if (item && item->text() == idToDelete) {
            // If the ID is found, delete the entire row
            ui->tableWidget->removeRow(row);
            QMessageBox::information(this, "Deletion", "Employee deleted successfully.");
            found = true;
            break;
        }
    }

    // If no matching ID was found, show a warning message
    if (!found) {
        QMessageBox::warning(this, "Deletion Error", "ID not found. Please enter a valid ID.");
    }
}
