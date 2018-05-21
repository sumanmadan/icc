//#pragma once

#ifndef CALCULATIONCHILDWINDOW_H
#define CALCULATIONCHILDWINDOW_H

#include <QtGui>
#include <QWidget>
#include <QMdiSubWindow>

class CalculationEditorForm;

class qCalculationChildMDIWindow : public QMdiSubWindow
{
	Q_OBJECT

public:
	explicit qCalculationChildMDIWindow(QWidget *parent = 0);
	~qCalculationChildMDIWindow();

private:
	CalculationEditorForm * calculationWidget;
};

#endif // CHILDWINDOW_H

