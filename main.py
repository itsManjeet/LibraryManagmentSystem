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
from operation import retrive, update
import datetime

now = datetime.datetime.now()

ui = 'ui/main.ui'

ui_window, QtBaseClass = uic.loadUiType(ui)

class Window(QMainWindow, ui_window):
    def __init__(self, parent=None):
        super(Window,self).__init__(parent)
        self.setupUi(self)
        self.rtrivbtn.clicked.connect(self.rtriv_clicked)
        self.edit_btn.clicked.connect(self.EditModeOn)
        self.update_btn.clicked.connect(self.update_clicked)

    def rtriv_clicked(self):
        self.roll = self.rollbox.text()
        data = retrive(self.roll)
        if not data:
            self.errlbl.setText("No Database found for %s"%roll)
        else:
            self.display_data(data)

    def display_data(self,data):
        self.namebox.setText(data['name'])
        sem = now.year - (2000 +  int(data['roll']) % 100)
        if data['fine'] == '':
            fine = "None"
        else:
            fine = data['fine']
        self.sembox.setText(str(sem*2))
        self.finebox.setText(fine)

        self.mbk1.setText(str(data['mbk1']))
        self.mbk2.setText(str(data['mbk2']))
        self.mbk3.setText(str(data['mbk3']))
        self.mbk4.setText(str(data['mbk4']))

        self.bbk1.setText(str(data['bbk1']))
        self.bbk2.setText(str(data['bbk2']))
        self.bbk3.setText(str(data['bbk3']))

    
    def EditModeOn(self):
        self.namebox.setReadOnly(False);
        self.finebox.setReadOnly(False);

        self.mbk1.setReadOnly(False);
        self.mbk2.setReadOnly(False);
        self.mbk3.setReadOnly(False);
        self.mbk4.setReadOnly(False);

        self.bbk1.setReadOnly(False);
        self.bbk2.setReadOnly(False);
        self.bbk3.setReadOnly(False);

    def EditModeOff(self):
        self.namebox.setReadOnly(True);
        self.finebox.setReadOnly(True);

        self.mbk1.setReadOnly(True);
        self.mbk2.setReadOnly(True);
        self.mbk3.setReadOnly(True);
        self.mbk4.setReadOnly(True);

        self.bbk1.setReadOnly(True);
        self.bbk2.setReadOnly(True);
        self.bbk3.setReadOnly(True);


    def update_clicked(self):
        data = {}
        data['name'] = self.namebox.text()
        data['roll'] = self.roll
        data['fine'] = self.finebox.text()

        data['mbk1'] = self.mbk1.text()
        data['mbk2'] = self.mbk2.text()
        data['mbk3'] = self.mbk3.text()
        data['mbk4'] = self.mbk4.text()

        data['bbk1'] = self.bbk1.text()
        data['bbk2'] = self.bbk2.text()
        data['bbk3'] = self.bbk3.text()

        update(data)
        self.errlbl.setText("Data Updated Successfully")
        self.EditModeOff()
        self.rtriv_clicked()


        

        

if __name__ == '__main__':
    app = QApplication(sys.argv)
    Librarien = Window()
    Librarien.show()

    sys.exit(app.exec_())