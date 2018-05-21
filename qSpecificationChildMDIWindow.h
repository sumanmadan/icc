
#ifndef QSPECIFICATIONCHILDMDIWINDOW_H
#define QSPECIFICATIONCHILDMDIWINDOW_H

#include <QtGui>
#include <QWidget>
#include <QMdiSubWindow>

class qSpecificationEditorForm;

class qSpecificationChildMDIWindow : public QMdiSubWindow
{
	Q_OBJECT

public:
	explicit qSpecificationChildMDIWindow(QWidget *parent = 0);
	~qSpecificationChildMDIWindow();

private:
	qSpecificationEditorForm * specificationWidget;
};

#endif // QSPECIFICATIONCHILDMDIWINDOW_H
