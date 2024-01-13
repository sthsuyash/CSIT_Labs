# Lab Assignment – III (JavaScript and XML)

1. Illustrate with examples the concept of alert, confirm and popup boxes • [Code](1_alert_confirm_popup.html)

2. WAP in javascript to demonstrate the objects, its properties and constructors with examples • [Code](2_objects.html)

3. How array can be created in javascript? Create 2-D array and display the array in HTML table • [Code](3_array.html)

4. Explain all the following built in objects with examples of each: • [Code](4_built_in_objects.html)

   - Array Methods
   - Date Methods
   - String Methods
   - Math Methods

.
5. WAP that contains a text field for name, age, phone number, email, dropdown for colleges, radio for gender and a checkboxes for i accept all the terms. Perform the client side validations as: • [Code](5_client-side-validation.html)

   - All fields are required
   - Name must contains alphabets and white spaces and of length greater than 6 characters long
   - Age must be integer and must be between and 50
   - Phone number must be exactly 10 digits long and must start with 98 or 97
   - Email must be valid

6. How events are handled in Javascript? Illustrate with examples • [Code](6_handling_events.html)

7. WAP to show the concept of Try/Catch • [Code](7_try_catch.html)

8. Write jQuery to show the concept of on click, on mouse out,onkeyup, on form submit events • [Code](8_jQuery.html)

9. Illustrate how jQuery effects(hide/show, fade, stop can be done in any image) • [Code](9_jquery_effects.html)

10. How animation is done using jQuery? Illustrate with exmaple • [Code](10_jquery_animation.html)

11. How json file is created? How can we parse the JSON file using JavaScript? • [Code](11_json.html)

12. How AJAX is used to get the data from the server to the client side? Illustrate with example • [Code](12_AJAX.html)

13. Create a simple XML element • [Code](13_simple.xml)

14. Create an XML document that conforms to the following DTD. • [Code](14_dtd.xml)

    ```xml
    <?xml version="1.0" encoding="UTF-8"?>
    <!ELEMENT Report (Students, Classes, Courses)>
    <!ELEMENT Students (Student*)>
    <!ELEMENT Classes (Class*)>
    <!ELEMENT Courses (Course*)>
    <!ELEMENT Student (Name, Status, CrsTaken*)>
    <!ELEMENT Name (First, Last)>
    <!ELEMENT First (#PCDATA)>
    <!ELEMENT Last (#PCDATA)>
    <!ELEMENT Status (#PCDATA)>
    <!ELEMENT CrsTaken (#PCDATA)>
    <!ELEMENT Class (Semester, ClassRoster)>
    <!ELEMENT Semester (#PCDATA)>
    <!ELEMENT ClassRoster (#PCDATA)>
    <!ELEMENT Course (#PCDATA)>
    <!ATTLIST Student StudId ID #REQUIRED>
    <!ATTLIST Course CrsCode ID #REQUIRED>
    <!ATTLIST CrsTaken CrsCode IDREF #REQUIRED>
    <!ATTLIST ClassRoster Members IDREFS #REQUIRED>
    ```

15. Create a XML document with simple and complex type • [Code](15_simple-complex.xml)

16. How XSLT is used to transform the XML document? Illustrate with example • [Code](16_xslt/transform.html)
