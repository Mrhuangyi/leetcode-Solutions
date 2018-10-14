/*
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？


*/

package leetcode;

class ListNode {
	int val;
	ListNode next;
	ListNode(int x) { val = x; }
}
public class RemoveNthFromEnd {
	static ListNode head = new ListNode(0);
	public static void main(String[] args) {
		// TODO Auto-generated method stub
        
        for(int i = 1; i <= 5; i++) {
        	addVal(i);
        }
        //ListNode res = removeNth(head, 3);
        ListNode res = removeNth2(head, 3);
        while(res != null) {
        	System.out.print(res.val + " ");
        	res = res.next;
        }
        System.out.print("\n");
	}
	public static void addVal(int val) {
		ListNode node = new ListNode(val);
		ListNode current = head;
		while(current.next != null) {
			current = current.next;
		}
		current.next = node;
	}
    public static ListNode removeNth(ListNode head, int n) {
    	// 时间复杂度O(n)，空间复杂度O(1）
    	ListNode dummy = new ListNode(0);
    	dummy.next = head;
    	ListNode first = dummy;
    	ListNode second = dummy;
    	for(int i = 0; i < n + 1; i++) {
    		first = first.next;
    	}
    	while(first != null) {
    		first = first.next;
    		second = second.next;
    	}
    	second.next = second.next.next;
    	return dummy.next;
    }
    public static ListNode removeNth2(ListNode head, int n) {
    	// 时间复杂度O(n),空间复杂度O(1)
    	ListNode dummy = new ListNode(0);
    	dummy.next = head;
    	int len = 0;
    	ListNode first = head;
    	while(first != null) {
    		len++;
    		first = first.next;
    	}
    	len = len - n;
    	first = dummy;
    	while(len > 0) {
    		len--;
    		first = first.next;
    	}
    	first.next = first.next.next;
    	return dummy.next;
    }
}
