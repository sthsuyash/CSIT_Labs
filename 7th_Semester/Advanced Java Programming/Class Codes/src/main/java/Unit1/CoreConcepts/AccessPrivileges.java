package Unit1.CoreConcepts;

/**
 * Access privileges are the restrictions that are applied to the class, methods, and fields of the class.
 * There are four types of access privileges in Java:
 * 1. Default: If no access modifier is specified then it is default. It is accessible only within the package.
 * 2. Private: It is accessible only within the class.
 * 3. Protected: It is accessible within the package and outside the package but through inheritance only.
 * 4. Public: It is accessible from anywhere.
 */

class DefaultClass {
    // default method: only accessible within the package
    void display() {
        System.out.println("This is a default class");
    }

    public void displayPublic() {
        System.out.println("This is a public method of default class");
    }

    protected void displayProtected() {
        System.out.println("This is a protected method of default class");
    }

    private void displayPrivate() {
        System.out.println("This is a private method of default class");
    }
}

public class AccessPrivileges {
    public static void main(String[] args) {
        // Accessing the default class
        DefaultClass defaultClass = new DefaultClass();
        defaultClass.display();
        defaultClass.displayProtected();
        defaultClass.displayPublic();
        // defaultClass.displayPrivate(); // private method is not accessible outside the class
    }
}
