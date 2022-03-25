#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    scene->setSceneRect(0, 0, WIN_X, WIN_Y);
}

MainWindow::~MainWindow()
{
    cmd_t cmd;
    cmd.type = FREE;
    cmd_manager(cmd);

    delete ui;
}

error_t MainWindow::draw_actions(void)
{
    canvas_t canvas;
    canvas.scene = ui->graphicsView->scene();
    canvas.width = canvas.scene->width();
    canvas.height = canvas.scene->height();

    cmd_t cmd;
    cmd.type = DRAW;
    cmd.canvas = canvas;

    error_t error_code = cmd_manager(cmd);

    return error_code;
}

void MainWindow::on_load_button_clicked(void)
{
    fname_t name = "data.txt";
    cmd_t cmd;

    cmd.type = LOAD;
    cmd.fname = name;

    error_t error_code = cmd_manager(cmd);
    if (error_code)
    {
        error_manager(error_code);
        return;
    }

    error_code = draw_actions();
    if (error_code)
    {
        error_manager(error_code);
    }
}

void MainWindow::on_move_button_clicked(void)
{
    move_params_t coeffs;
    coeffs.dx = ui->dx_box->value();
    coeffs.dy = ui->dy_box->value();
    coeffs.dz = ui->dz_box->value();

    cmd_t cmd;
    cmd.type = MOVE;
    cmd.move_params = coeffs;

    error_t error_code = cmd_manager(cmd);
    if (error_code)
    {
        error_manager(error_code);
        return;
    }

    error_code = draw_actions();
    if (error_code)
    {
        error_manager(error_code);
    }
}

void MainWindow::on_scale_button_clicked(void)
{
    scale_params_t params;
    coefs_t coefs;

    coefs.kx = ui->kx_box->value();
    coefs.ky = ui->ky_box->value();
    coefs.kz = ui->kz_box->value();

    params.coefs = coefs;

    point_t about;

    about.x = 0;
    about.y = 0;
    about.z = 0;

    params.about = about;

    cmd_t cmd;
    cmd.type = SCALE;
    cmd.scale_params = params;

    error_t error_code = cmd_manager(cmd);
    if (error_code)
    {
        error_manager(error_code);
        return;
    }

    error_code = draw_actions();
    if (error_code)
    {
        error_manager(error_code);
    }
}

void MainWindow::on_turn_button_clicked(void)
{
    rotate_params_t params;
    angles_t angles;
    angles.ax = ui->ox_box->value();
    angles.ay = ui->oy_box->value();
    angles.az = ui->oz_box->value();

    point_t about;
    about.x = 0;
    about.y = 0;
    about.z = 0;

    params.about = about;
    params.angles = angles;

    cmd_t cmd;
    cmd.type = ROTATE;
    cmd.rotate_params = params;

    error_t error_code = cmd_manager(cmd);
    if (error_code)
    {
        error_manager(error_code);
        return;
    }

    error_code = draw_actions();
    if (error_code)
    {
        error_manager(error_code);
    }
}
