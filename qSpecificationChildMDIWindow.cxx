#include "qSpecificationChildMDIWindow.h"


#include <QMdiSubWindow>

#include "Apps/qOasis/qSpecificationEditorForm.h"

qSpecificationChildMDIWindow::qSpecificationChildMDIWindow(QWidget *parent) :
	QMdiSubWindow(parent), specificationWidget( new qSpecificationEditorForm)
{
	this->setWidget(specificationWidget);
}

qSpecificationChildMDIWindow::~qSpecificationChildMDIWindow()
{
	specificationWidget->~qSpecificationEditorForm();
}
