
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <functional>
#include <numeric>
#include <regex>

#include <QtWidgets>
#include <QStandardItemModel>
#include <QTableView>
#include <QModelIndex>
#include <QVariant>

#include "Apps/qOasis/qOasisMainWindow.h"
#include "Apps/qOasis/qCalculationChildMDIWindow.h"
#include "Apps/qOasis/qSpecificationChildMDIWindow.h"


qOasisMainWindow::qOasisMainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	//this->setCentralWidget(mdiArea);
	//this->tableView = new QTableView();
	//this->setCentralWidget(this->tableView);
	//this->wafer = std::make_shared<gfWafer>();

	readSettings();
	//setWindowIcon(QIcon(":/images/icon.png"));

	//this->ui->dateEdit->setDate(QDate(currentYear, 1, 1));
	//this->ui->dateEdit->setMaximumDate(QDate(currentYear, 12, 1));

	this->initializeRawParameters();
	//initializeStatusBar();
	//initializeTableView();

	setAttribute(Qt::WA_DeleteOnClose);
}

qOasisMainWindow::~qOasisMainWindow()
{
	delete ui;
}

void qOasisMainWindow::about()
{
	QMessageBox::about(this, tr("About Spreadsheet"),
		tr("<h2>DataCheckGUI 1.0</h2>"
			"<p>Copyright &copy; 2017 Software Inc."
			"<p>Spreadsheet is a small application that "
			"demonstrates QAction, QMainWindow, QMenuBar, "
			"QStatusBar, QTableWidget, QToolBar, and many other "
			"Qt classes."));
}

void qOasisMainWindow::initializeStatusBar()
{
	//locationLabel = new QLabel(" W999 ");
	//locationLabel->setAlignment(Qt::AlignHCenter);
	//locationLabel->setMinimumSize(locationLabel->sizeHint());

	//statusLabel = new QLabel(this);
	//statusProgressBar = new QProgressBar(this);

	//formulaLabel = new QLabel;
	//formulaLabel->setIndent(3);

	//statusBar()->addWidget(locationLabel);
	//statusBar()->addWidget(formulaLabel, 1);

	//connect(this->spreadsheet, SIGNAL(currentCellChanged(int, int, int, int)), this, SLOT(updateStatusBar()));
	//connect(this->spreadsheet, SIGNAL(modified()), this, SLOT(spreadsheetModified()));
	//connect(this->dateEdit, SIGNAL(modified()), this, SLOT(updateStatusBar()));
	//updateStatusBar();
}

void qOasisMainWindow::initializeRawParameters()
{
	//ui->rawParamListView

	// Create model
	QStandardItemModel *model = new QStandardItemModel(this);

	// Make data
	QStringList List;
	List << "BT11_K2_Cap_Total~Cond100KHz" << "BT11_K2_Cap_lateral_Short~Lk" << "BT11_G1_Cap_Total~Cap100KHz" << "BT11_G1_Cap_Total~Cond100KHz" << "BT11_G2_Cap_Total~Cap100KHz" << "BT11_G2_Cap_Total~Cond100KHz" << "bb_revP064_M1_1b_latRPD_lowRpc~Vtlin" << "bb_revP064_M1_1b_latRPD_lowRpc~Vtsat" << "bb_revP064_M1_1b_latRPD_lowRpc~DIBL" << "bb_revP064_M1_1b_latRPD_lowRpc~Iodlin4" << "bb_revP064_M2_16Kb_lat~080Isb_t" << "bb_revP064_M1_1b_latLPD_lowRpc~Vtlin" << "bb_revP064_M1_1b_latLPD_lowRpc~Vtsat" << "bb_revP064_M1_1b_latLPD_lowRpc~DIBL" << "bb_revP064_M1_1b_latLPD_lowRpc~Iodlin4" << "bb_revP064_M1_1b_latLPD_lowRpc~Idsat" << "bb_revP064_M1_1b_latLPG_lowRpc~Vtlin" << "bb_revP064_M1_1b_latLPG_lowRpc~Vtsat" << "bb_revP064_M1_1b_latLPG_lowRpc~DIBL" << "bb_revP064_M1_1b_latLPG_lowRpc~Iodlin4" << "bb_revP064_M1_1b_latLPG_lowRpc~Idsat" << "bb_revP064_M1_1b_latLPU_lowRpc~Vtlin" << "bb_revP064_M1_1b_latLPU_lowRpc~Vtsat" << "bb_revP064_M1_1b_latLPU_lowRpc~DIBL" << "bb_revP064_M1_1b_latLPU_lowRpc~Iodlin4" << "bb_revP064_M1_1b_latLPU_lowRpc~Idsat" << "bb_revP064_M1_1b_lat_lowRpc~080Iread_BLT" << "bb_revP064_M1_1b_lat_lowRpc~080Iread_BLC" << "bb_revP064_M1_1b_lat_lowRpc~080SNML" << "bb_revP064_M1_1b_lat_lowRpc~080SNMR" << "bb_revP064_M1_1b_lat_lowRpc~080SNM" << "bb_revP080_M1_1b_latRPG_lowRpc~Idsat" << "bb_revP080_M1_1b_latRPU_lowRpc~Idsat" << "bb_revP080_M1_1b_latLPD_lowRpc~Vtlin" << "bb_revP080_M1_1b_latLPD_lowRpc~Vtsat" << "bb_revP080_M1_1b_latLPD_lowRpc~DIBL";

	model->setHorizontalHeaderItem(0, new QStandardItem(QString("Name")));
	//model->setColumnWidth(0, 255);
	model->setHorizontalHeaderItem(1, new QStandardItem(QString("Type")));
	//model->setColumnWidth(1, 4);
	model->setHorizontalHeaderItem(2, new QStandardItem(QString("Specs")));
	//model->setColumnWidth(2, 3);

	int row = 0;
	int random = rand() % 2;
	for (QString listItem : List) {
		QStandardItem *firstRow = new QStandardItem(QString(listItem));
		model->setItem(row, 0, firstRow);

		QString type = random  == 0 ? "Raw" : "Calc";
		model->setItem(row, 1, new QStandardItem(type));

		random = rand() % 2;

		QString specs = random == 0 ? "X" : " ";
		model->setItem(row, 2, new QStandardItem(specs));

		random = rand() % 2;
		++row;
	}
	// Populate our model
	//model->setStringList(List);
	//model->setHeader

	// Glue model and view together
	//ui->listView->setModel(model);
	//ui->comboBox->setModel(model);
	ui->paramTable->setModel(model);
	ui->paramTable->setAlternatingRowColors(true);
	ui->paramTable->setAutoFillBackground(true);
	//ui->paramTable->setHorizontalHeader();
}

void qOasisMainWindow::updateStatusBar()
{
}

void qOasisMainWindow::readSettings()
{
	QSettings settings("GLOBALFOUNDRIES Inc.", "DataCheckGUI");

	restoreGeometry(settings.value("geometry").toByteArray());

	//bool showGrid = settings.value("showGrid", true).toBool();
	//showGridAction->setChecked(showGrid);

	//bool autoRecalc = settings.value("autoRecalc", true).toBool();
	//autoRecalculateAction->setChecked(autoRecalc);

}

void qOasisMainWindow::writeSettings()
{
	QSettings settings("GLOBALFOUNDRIES Inc.", "DataCheckGUI");

	settings.setValue("geometry", this->saveGeometry());
}

qCalculationChildMDIWindow *qOasisMainWindow::createMdiChild()
{
	qCalculationChildMDIWindow *child = new qCalculationChildMDIWindow;
	mdiArea->addSubWindow(child);

#ifndef QT_NO_CLIPBOARD
	//connect(child, &QTextEdit::copyAvailable, cutAct, &QAction::setEnabled);
	//connect(child, &QTextEdit::copyAvailable, copyAct, &QAction::setEnabled);
#endif

	return child;
}

void qOasisMainWindow::createCalculationEditorChild()
{
	qCalculationChildMDIWindow *childWindow = new qCalculationChildMDIWindow(ui->mdiArea);
	childWindow->setAttribute(Qt::WA_DeleteOnClose);
	childWindow->show();
}

void qOasisMainWindow::createSpecificationEditorChild()
{
	qSpecificationChildMDIWindow *childWindow = new qSpecificationChildMDIWindow(ui->mdiArea);
	childWindow->setAttribute(Qt::WA_DeleteOnClose);
	childWindow->show();
}
