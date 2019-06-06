from sqlalchemy import create_engine, MetaData, Column, Integer, Table, String, Date, ARRAY

engine = create_engine('sqlite:///Database/student.db', echo = True)
meta = MetaData()
connect = engine.connect()

Student = Table(
    'STUDENT', meta,
    Column('ROLLNO',Integer,primary_key=True),
    Column('NAME',String),
    Column('MONTHLYBOOK1',Integer),
    Column('MONTHLYBOOK2',Integer),
    Column('MONTHLYBOOK3',Integer),
    Column('MONTHLYBOOK4',Integer),
    Column('BOOKBANK1',Integer),
    Column('BOOKBANK2',Integer),
    Column('BOOKBANK3',Integer),
    Column('FINE',Integer),
)


meta.create_all(engine)