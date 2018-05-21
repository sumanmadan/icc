
#ifndef SPECIFICATIONEDITORFORM_H
#define SPECIFICATIONEDITORFORM_H

#include "ui_SpecificationEditorForm.h"

class qSpecificationEditorForm : public QWidget
{
	Q_OBJECT

public:
	explicit qSpecificationEditorForm(QWidget *parent = nullptr);

	private slots:

private:
	Ui::SpecificationEditorForm ui;
};

#endif