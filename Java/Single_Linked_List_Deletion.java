import java.util.Scanner;

public class Single_LL_Deletion {
    Node head = null;

    public Single_LL_Deletion() {
    }

    public void creation() {
        Scanner sc = new Scanner(System.in);

        int n;
        do {
            System.out.println("Enter data: ");
            int data = sc.nextInt();
            Node new_node = new Node(data);
            if (this.head == null) {
                this.head = new_node;
            } else {
                System.out.println("Enter 1 to insert the item at the beginning, 2 to insert the item at the end, 3 to insert the item at any specific location");
                int w = sc.nextInt();
                switch (w) {
                    case 1:
                        new_node.next = this.head;
                        this.head = new_node;
                        break;
                    case 2:
                        Node check;
                        for(check = this.head; check.next != null; check = check.next) {
                        }

                        check.next = new_node;
                        break;
                    case 3:
                        Node tempins = this.head;
                        System.out.println("Enter the data of the location after which you want to insert new node:");

                        for(int insdat = sc.nextInt(); tempins.data != insdat; tempins = tempins.next) {
                        }

                        new_node.next = tempins.next;
                        tempins.next = new_node;
                }
            }

            System.out.println("Do you want to add more data?If 'Yes' press 0: ");
            n = sc.nextInt();
        } while(n == 0);

    }

    public void traverse() {
        Node temp = this.head;
        if (this.head == null) {
            System.out.println("Linked List doesn't exist.");
        } else {
            while(temp != null) {
                System.out.println(temp.data);
                temp = temp.next;
            }
        }

    }

    public void deletion() {
        Scanner sc = new Scanner(System.in);

        int n;
        do {
            if (this.head == null) {
                System.out.println("Linked List doesn't exists.");
            } else {
                System.out.println("Enter 1 to delete the item at the beginning, 2 to delete the item at the end, 3 to delete the item at any specific location");
                int w = sc.nextInt();
                switch (w) {
                    case 1:
                        this.head = this.head.next;
                        break;
                    case 2:
                        Node temp = this.head;

                        for(Node ptr = temp.next; ptr.next != null; ptr = ptr.next) {
                            temp = ptr;
                        }

                        temp.next = null;
                        break;
                    case 3:
                        Node temploc = this.head;
                        Node ptrloc = temploc.next;
                        System.out.println("Enter the data of the location which you want to delete:");

                        for(int delloc = sc.nextInt(); ptrloc.data != delloc; ptrloc = ptrloc.next) {
                            temploc = ptrloc;
                        }

                        temploc.next = ptrloc.next;
                }
            }

            System.out.println("Do you want to delete more data?If 'Yes' press 0: ");
            n = sc.nextInt();
        } while(n == 0);

    }

    public static void main(String[] args) {
        Single_LL_Deletion s3 = new Single_LL_Deletion();
        s3.creation();
        s3.deletion();
        s3.traverse();
    }

    static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }
}
