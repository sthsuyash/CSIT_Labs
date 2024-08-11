# Unit 4: Database Connectivity

JDBC (Java Database Connectivity)

If you want to run the JDBC program, but do not want to install MySQL on your machine, you can use Docker to run a MySQL
container.

Use the following commands in order to run a MySQL container: (Make sure you have Docker installed on your machine)

1. Pull the MySQL image from Docker Hub

   ```bash
   docker pull mysql:latest
   ```

2. Run the MySQL container

   ```bash
   docker run --name mysql-db -e MYSQL_ROOT_PASSWORD=password -p 3306:3306 -d mysql:latest
   ```

3. Access the MySQL container

   ```bash
   docker exec -it mysql-db bash
   ```

   ```bash
   mysql -u root -p
   # The password is "password"
   ```

4. Create a database

   ```sql
   CREATE DATABASE primecsitb; -- or any name you want
   ```

5. Run the JDBC program
