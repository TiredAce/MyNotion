package com.coreOfJava.part_5;


public class Main {
    public static void main(String[] args) {
        Employee[] staff = new Employee[3];
        staff[0] = new Manager();
        staff[1] = new Employee();
        Manager boss1 = (Manager) staff[0];
        Employee e = new Employee();

//        Manager boss2 = (Manager) staff[1]; 会出现异常，因为staff[1]不是Manager类型
    }
}

class A {
    private int a;
    public final void print(int x) {
        System.out.println("A");
    }
}

class B extends A{
    private int b;
    public void print(int x, int y) {

    }
}

abstract class Person {
    private String name;
    public abstract String getName();
}

class Employee {
    private String name;
    public boolean equals(Object otherObject) {
        if (this == otherObject) return true;
        if (otherObject == null) return false;
        if (getClass() != otherObject.getClass()) return false;
        return name.equals(((Employee) otherObject).name);
    }
}

class Manager extends Employee{


}
