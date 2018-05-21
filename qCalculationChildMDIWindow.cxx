#include "qCalculationChildMDIWindow.h"


#include <QMdiSubWindow>

#include "Apps/qOasis/qCalculationEditorForm.h"

qCalculationChildMDIWindow::qCalculationChildMDIWindow(QWidget *parent) :
	QMdiSubWindow(parent), calculationWidget( new CalculationEditorForm)
{
	this->setWidget(calculationWidget);
}

qCalculationChildMDIWindow::~qCalculationChildMDIWindow()
{
	calculationWidget->~CalculationEditorForm();
}
