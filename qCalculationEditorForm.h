
#ifndef CALCULATIONEDITORFORM_H
#define CALCULATIONEDITORFORM_H

#include "ui_CalculationEditorForm.h"

class CalculationEditorForm : public QWidget
{
	Q_OBJECT

public:
	explicit CalculationEditorForm(QWidget *parent = nullptr);

	private slots:

private:
	Ui::CalculationEditorForm ui;
};

#endif