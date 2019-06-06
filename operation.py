from database import connect, Student
from sqlalchemy import text

def StudentData(Roll):
    query = text("SELECT * FROM STUDENT where ROLLNO = :x")
    try:
        data = connect.execute(query,x = Roll ).fetchall()[0]
    except IndexError as e:
        if str(e) == 'list index out of range':
            return None

    print(data)
    student = {
        'RollNo':data[0],
        'Name':data[1],
        'MonthlyBooks':data[2:5],
        'BookBank':data[6:8],
        'Fine' : data[9]
    }

    return student

def AddBookBank(data,Book):
    BookBank = data['BookBank']
    j = 0
    for i in BookBank:
        print("Book : ",i)
        if i == '':
            print("None found")
            query = text("UPDATE STUDENT SET :x = :a WHERE ROLLNO = :y")
            BK = "BOOKBANK%d"%j
            data = connect.execute(query,x = BK, a = Book, y = data['RollNo'])
            print(data)
        j += 1

        
