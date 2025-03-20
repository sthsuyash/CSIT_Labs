import ZODB, ZODB.FileStorage
import transaction
import persistent


# Define the Employee class
class Employee(persistent.Persistent):
    def __init__(self, eid, name, department):
        self.eid = eid
        self.name = name
        self.department = department

    def __str__(self):
        return f"ID: {self.eid}, Name: {self.name}, Department: {self.department}"


# Initialize the ZODB database
storage = ZODB.FileStorage.FileStorage("employee.fs")
db = ZODB.DB(storage)
connection = db.open()
root = connection.root()

# Initialize employee storage if not already present
if not hasattr(root, "employees"):
    root.employees = {}


# Function to add employees
def add_employee(eid, name, department):
    if eid in root.employees:
        print(f"Employee with ID {eid} already exists.")
        return
    root.employees[eid] = Employee(eid, name, department)
    transaction.commit()
    print(f"Employee {name} added successfully.")


# Function to retrieve all employees
def get_all_employees():
    print("\nEmployee List:")
    for emp in root.employees.values():
        print(emp)


# Function to fetch employee by ID
def get_employee_by_id(eid):
    emp = root.employees.get(eid, None)
    if emp:
        print(f"\nEmployee Found: {emp}")
    else:
        print(f"\nEmployee with ID {eid} not found.")


# Adding employees
add_employee(101, "Alice", "HR")
add_employee(102, "Bob", "Engineering")

# Retrieving all employees
get_all_employees()

# Searching for an employee by ID
get_employee_by_id(102)

# Closing database connection
connection.close()
db.close()
