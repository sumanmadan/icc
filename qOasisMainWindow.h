#ifndef QOASISMAINWINDOW_H
#define QOASISMAINWINDOW_H

#include <memory>
#include <unordered_map>
#include <string>

#include "Apps/qOasis/ui_MainWindow.h"


class QMdiArea;
class gfPublicIndex;
class gfDataTableModel;
class QTableView;
class QProgressBar;
class qCalculationChildMDIWindow;

class qOasisMainWindow : public QMainWindow, public Ui::MainWindow
{
	Q_OBJECT

public:
	explicit qOasisMainWindow(QWidget * parent = nullptr);
	~qOasisMainWindow();

private slots:
	void about();
	void updateStatusBar();

	qCalculationChildMDIWindow *createMdiChild();
	void createCalculationEditorChild();
	void createSpecificationEditorChild();

private:
	void initializeStatusBar();
	void initializeTableView();

	void initializeRawParameters();

	void readSettings();
	void writeSettings();

	// child windows
	qCalculationChildMDIWindow *activeMdiChild() const;
	QMdiSubWindow *findMdiChild(const QString &fileName) const;




	//QMdiArea *mdiArea;
	//gfWafer *wafer;

	Ui::MainWindow * ui;
};

#endif