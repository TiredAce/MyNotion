package com.coreOfJava.Part6;

public class Employee implements Comparable<Employee>{
    private double salary;

    public int compareTo(Employee otherObject) {
        return Double.compare(salary, otherObject.salary);
    }
}
