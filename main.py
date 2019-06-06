#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Library Management System

Author : Manjeet Singh
Website : itsmanjeet.github.io
License : GPL3
"""

import sys
from PyQt5 import QtWidgets, uic
from PyQt5.QtWidgets import QMainWindow, QApplication
from PyQt5 import Qt
from operation import StudentData, AddBookBank
import datetime

now = datetime.datetime.now()

ui = 'ui/main.ui'
student_ui = 'ui/student.ui'

ui_window, QtBaseClass = uic.loadUiType(ui)
ui_student, QtStudentClass = uic.loadUiType(student_ui)

class Window(QMainWindow, ui_window):
    def __init__(self, parent=None):
        super(Window,self).__init__(parent)
        self.setupUi(self)
        self.searchbtn.clicked.connect(self.SearchRoll)

    def SearchRoll(self):
        self.roll = self.rollbox.text()
        self.data = StudentData(self.roll)
        if self.data == None:
            self.errlbl.setText("No Database found for %s"%self.roll)
        else:
            self.errlbl.setText("Database Found for %s"%self.roll)
            s = Student(self)
            s.show()
        

class Student(QMainWindow, ui_student):
    def __init__(self,parent):
        super(Student,self).__init__(parent)
        self.setupUi(self)
        self.data = parent.data

        self.upd_book_bank.clicked.connect(self.UpdateBookBank)
        self.namebox.setText(parent.data['Name'])
        self.rollbox.setText(str(parent.data['RollNo']))
        self.sembox.setText(str(self.CalSem(parent.roll)))
        self.finebox.setText(str(parent.data['Fine']))

        for book in parent.data['BookBank']:
            if book != None:
                self.book_bank.addItem(str(book))
        
        for book in parent.data['MonthlyBooks']:
            if book != None:
                self.mon_book.addItem(str(book))

    def CalSem(self,roll):
        rol = int(roll)
        sem = (now.year - (2000 + (rol % 100))) * 2
        return sem

    def UpdateBookBank(self):
        AddBookBank(self.data,1234)

if __name__ == '__main__':
    app = QApplication(sys.argv)
    Librarien = Window()
    Librarien.show()

    sys.exit(app.exec_())