#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QRegularExpression>

                       MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    // Настройка радиокнопок: изначально ни одна не выбрана
    ui->radioPaper->setAutoExclusive(false);
    ui->radioElectronic->setAutoExclusive(false);
    ui->radioPaper->setChecked(false);
    ui->radioElectronic->setChecked(false);
    ui->radioPaper->setAutoExclusive(true);
    ui->radioElectronic->setAutoExclusive(true);

    // Подключение сигналов
    connect(ui->saveButton, &QPushButton::clicked, this, &MainWindow::onSaveClicked);
    connect(ui->resetButton, &QPushButton::clicked, this, &MainWindow::onResetClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onSaveClicked()
{
    QString errorMsg;
    if (!validateFields(errorMsg))
    {
        QMessageBox::critical(this, "Ошибка", errorMsg);
        return;
    }

    // Тип издания
    QString type;
    if (ui->radioPaper->isChecked())
        type = ui->radioPaper->text();
    else if (ui->radioElectronic->isChecked())
        type = ui->radioElectronic->text();

    // Жанры
    QStringList selectedGenres;
    if (ui->genreDetective->isChecked())
        selectedGenres << ui->genreDetective->text();
    if (ui->genreFantasy->isChecked())
        selectedGenres << ui->genreFantasy->text();
    if (ui->genreRomance->isChecked())
        selectedGenres << ui->genreRomance->text();
    QString genre = selectedGenres.join(", ");

    Book item(ui->authorEdit->text().trimmed(),
                  ui->titleEdit->text().trimmed(),
                  ui->codeEdit->text().trimmed(),
                  ui->ratioEdit->text().trimmed(),
                  type,
                  genre);

    if (item.saveToFile("result.txt"))
    {
        QMessageBox::information(this, "Успех", "Данные сохранены в result.txt");
        onResetClicked();
    }
    else
    {
        QMessageBox::critical(this, "Ошибка", "Не удалось сохранить файл");
    }
}

void MainWindow::onResetClicked()
{
    ui->authorEdit->clear();
    ui->titleEdit->clear();
    ui->codeEdit->clear();
    ui->ratioEdit->clear();

    // Сброс радиокнопок типа издания
    ui->radioPaper->setAutoExclusive(false);
    ui->radioElectronic->setAutoExclusive(false);
    ui->radioPaper->setChecked(false);
    ui->radioElectronic->setChecked(false);
    ui->radioPaper->setAutoExclusive(true);
    ui->radioElectronic->setAutoExclusive(true);

    // Сброс чекбоксов жанра
    ui->genreDetective->setChecked(false);
    ui->genreFantasy->setChecked(false);
    ui->genreRomance->setChecked(false);
}

bool MainWindow::validateFields(QString &errorMessage)
{
    // Обязательные поля (жанр не обязателен)
    if (ui->authorEdit->text().trimmed().isEmpty())
    {
        errorMessage = "Поле 'Автор' не заполнено.";
        return false;
    }
    if (ui->titleEdit->text().trimmed().isEmpty())
    {
        errorMessage = "Поле 'Название' не заполнено.";
        return false;
    }
    if (ui->codeEdit->text().trimmed().isEmpty())
    {
        errorMessage = "Поле 'Код' не заполнено.";
        return false;
    }
    if (ui->ratioEdit->text().trimmed().isEmpty())
    {
        errorMessage = "Поле 'Дробь' не заполнено.";
        return false;
    }
    if (!ui->radioPaper->isChecked() && !ui->radioElectronic->isChecked())
    {
        errorMessage = "Поле 'Тип издания' не выбрано.";
        return false;
    }

    // Автор: русское слово + пробел + 1-2 заглавные буквы
    QRegularExpression authorRegex("^[А-ЯЁ][а-яё]+\\s+[А-ЯЁ]{1,2}$");
    if (!authorRegex.match(ui->authorEdit->text().trimmed()).hasMatch())
    {
        errorMessage = "Автор должен быть в формате: Иванов ИВ (русское слово, пробел, одна или две заглавные буквы).";
        return false;
    }

    // Название: в двойных кавычках, не пустое внутри
    QRegularExpression titleRegex("^\".+\"$");
    if (!titleRegex.match(ui->titleEdit->text().trimmed()).hasMatch())
    {
        errorMessage = "Название должно быть в двойных кавычках и не пустым, например: \"Война и мир\".";
        return false;
    }

    // Код: три цифры, дефис, пять цифр
    QRegularExpression codeRegex("^\\d{3}-\\d{5}$");
    if (!codeRegex.match(ui->codeEdit->text().trimmed()).hasMatch())
    {
        errorMessage = "Код должен быть в формате: 123-12345 (три цифры, дефис, пять цифр).";
        return false;
    }

    // Дробь: число/число, второе меньше первого
    QRegularExpression ratioRegex("^(\\d+)/(\\d+)$");
    auto match = ratioRegex.match(ui->ratioEdit->text().trimmed());
    if (!match.hasMatch())
    {
        errorMessage = "Дробь должна быть в формате: число/число, например 2/1.";
        return false;
    }
    int num1 = match.captured(1).toInt();
    int num2 = match.captured(2).toInt();
    if (num2 >= num1)
    {
        errorMessage = "В дроби второе число должно быть меньше первого.";
        return false;
    }

    return true;
}
