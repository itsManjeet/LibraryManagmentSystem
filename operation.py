from database import connect, Student
from sqlalchemy import text

def retrive(roll):
    query = text("SELECT * FROM STUDENT WHERE ROLLNO = :x")
    try:
        data = connect.execute(query,x = roll ).fetchall()[0]
    except IndexError as e:
        if str(e) == 'list index out of range':
            return None

    print(data)
    
    student_data = {
        'roll' : data[0],
        'name' : data[1],
        'mbk1' : data[2],
        'mbk2' : data[3],
        'mbk3' : data[4],
        'mbk4' : data[5],
        'bbk1' : data[6],
        'bbk2' : data[7],
        'bbk3' : data[8],
        'fine' : data[9],
    }

    return student_data
     

def update(data):
    query = text("UPDATE STUDENT SET NAME=:n, MONTHLYBOOK1=:a, MONTHLYBOOK2=:b, MONTHLYBOOK3=:c, MONTHLYBOOK4=:d, BOOKBANK1=:e, BOOKBANK2=:f, BOOKBANK3=:g, FINE=:h WHERE ROLLNO=:r")
    try:
        data = connect.execute(query,n = data['name'],
                                     a = data['mbk1'],
                                     b = data['mbk2'],
                                     c = data['mbk3'],
                                     d = data['mbk4'],
                                     e = data['bbk1'],
                                     f = data['bbk2'],
                                     g = data['bbk3'],
                                     h = data['fine'],
                                     r = data['roll']).fetchall()
    except Exception as e:
        print(e)

    print(data)