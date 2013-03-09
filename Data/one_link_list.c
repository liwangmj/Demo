#include <stdio.h>
#include <stdlib.h>

typedef struct LINK_LIST_NODE {
	int data;
	struct LINK_LIST_NODE *next;
} LINK_LIST_NODE, *LINK_LIST_NODE_PTR;

LINK_LIST_NODE_PTR init_link_list(void);
int creat_link_list(LINK_LIST_NODE_PTR head_node);
int print_link_list(LINK_LIST_NODE_PTR head_node);
int insert_link_list(LINK_LIST_NODE_PTR head_node);
int delete_link_list(LINK_LIST_NODE_PTR head_node);
int revise_link_list(LINK_LIST_NODE_PTR head_node);
int find_link_list(LINK_LIST_NODE_PTR head_node);
int switch_on_off(LINK_LIST_NODE_PTR head_node);

int main(int argc, char const *argv[])
{
	LINK_LIST_NODE_PTR head_node = init_link_list();
	switch_on_off(head_node);
	return 0;
}

LINK_LIST_NODE_PTR init_link_list(void)
{
	LINK_LIST_NODE_PTR head_node;
	head_node = (LINK_LIST_NODE_PTR)malloc(sizeof(LINK_LIST_NODE));
	head_node->data = 0;
	head_node->next = NULL;
	return head_node;
}

int creat_link_list(LINK_LIST_NODE_PTR head_node)
{
	if (NULL != head_node->next) {
		printf("Creat ERROR: link list is exist!\n\n");
		return -1;
	}
	LINK_LIST_NODE_PTR tmp_node = NULL;
	LINK_LIST_NODE_PTR work_head_node = head_node;
	int tmp_data = 0;
	printf("Please input init data:\n");
	while (scanf("%d", &tmp_data) != EOF) {
		tmp_node = (LINK_LIST_NODE_PTR)malloc(sizeof(LINK_LIST_NODE));
		tmp_node->data = tmp_data;
		tmp_node->next = work_head_node->next;
		work_head_node->next = tmp_node;
		work_head_node = tmp_node;
		head_node->data++;
	}
	return 0;
}

int print_link_list(LINK_LIST_NODE_PTR head_node)
{
	LINK_LIST_NODE_PTR work_node = head_node;
	int tmp_node = 0;
	while (NULL != work_node->next) {
		printf("Node%d data:\t%d\n", tmp_node + 1, work_node->data);
		work_node = work_node->next;
		tmp_node++;
	}
	printf("\nList count: %d\n\n", head_node->data);
	return 0;
}

int insert_link_list(LINK_LIST_NODE_PTR head_node)
{
	LINK_LIST_NODE_PTR work_head_node = head_node;
	LINK_LIST_NODE_PTR tmp_node = NULL;
	int tmp_data;
	printf("Please input need insert is data:\n");
	while (scanf("%d", &tmp_data) != EOF) {
		while (NULL != work_head_node->next) {
			work_head_node = work_head_node->next;
		}
		tmp_node = (LINK_LIST_NODE_PTR)malloc(sizeof(LINK_LIST_NODE));
		tmp_node->data = tmp_data;
		tmp_node->next = work_head_node->next;
		work_head_node->next = tmp_node;
		work_head_node = tmp_node;
		head_node->data++;
		printf("Insert data is OK! Please new insert:\n");
		getchar();
	}
	printf("Insert end!\n");
	return 0;
}

int delete_link_list(LINK_LIST_NODE_PTR head_node)
{
	LINK_LIST_NODE_PTR work_head_node = head_node;
	LINK_LIST_NODE_PTR tmp_node = NULL;
	int tmp_data = 0;
	int select = 0;
	printf("Please select delete mode:\n");
	while (1) {
		scanf("%d", &select);
		if (select == 1) {
			while (NULL != work_head_node->next) {
				tmp_node = work_head_node->next;
				work_head_node->next->data = 0;
				work_head_node->next = work_head_node->next->next;
				free(tmp_node);
				head_node->data--;
			}
			printf("Delete all data OK!\n\n");
			return 0;
		} else if (select == 2) {
			tmp_data = 0;
			printf("Please input need delete node is data:\n");
			scanf("%d", &tmp_data);
			while (tmp_data != work_head_node->next->data || NULL != work_head_node->next) {
				work_head_node->next = work_head_node->next->next;
			}
			if (tmp_data == work_head_node->next->data) {
				tmp_node = work_head_node->next;
				work_head_node->next->data = 0;
				work_head_node->next = work_head_node->next->next;
				free(tmp_node);
				head_node->data--;
				printf("Delete single data OK!\n");
				continue;
			}
			if (NULL == work_head_node->next) {
				work_head_node = head_node;
				printf("Need delete data node nothingness!\n\n");
				continue;
			}
		} else {
			printf("Select error, please again select:\n\n");
		}
	}
}

int revise_link_list(LINK_LIST_NODE_PTR head_node)
{
	LINK_LIST_NODE_PTR work_head_node = head_node;
	int tmp_data = 0;
	printf("Please input need revise is data:\n");
	getchar();
	while (scanf("%d", &tmp_data) != EOF) {
		tmp_data = 0;
		while (tmp_data != work_head_node->next->data) {
			work_head_node->next = work_head_node->next->next;
		}
		if (tmp_data == work_head_node->next->data) {
			printf("Need revise is:\n");
			getchar();
			scanf("%d", &tmp_data);
			work_head_node->next->data = tmp_data;
			printf("Revise OK!\n\n");
			printf("Continue revise please input:\n");
		} else {
			printf("Need revise data is nothingness!\n\n");
			printf("Please again input:\n");
		}
	}
	return 0;
}

int find_link_list(LINK_LIST_NODE_PTR head_node)
{
	LINK_LIST_NODE_PTR work_head_node = head_node;
	int tmp_data = 0;
	int tmp_count = 0;
	printf("Please input need find is data:\n");
	getchar();
	while (scanf("%d", &tmp_data) != EOF) {
		tmp_count = 0;
		while (tmp_data != work_head_node->next->data || NULL != work_head_node->next) {
			work_head_node->next = work_head_node->next->next;
			tmp_count++;
		}
		if (tmp_data == work_head_node->next->data) {
			printf("Node%d data is:%d\n", tmp_count, work_head_node->next->data);
			printf("Continue input find is data:\n");
		} else {
			printf("Find is data nothingness!\n");
			printf("Please again input:\n");
			getchar();
		}
	}
}

int switch_on_off(LINK_LIST_NODE_PTR head_node)
{
	int select_on_off = 0;
	while (1) {
		printf("Init link list (1)\n");
		printf("Creat link list (2)\n");
		printf("Print link list (3)\n");
		printf("Insert link list (4)\n");
		printf("Delete link list (5)\n");
		printf("Revise link list (6)\n");
		printf("Find link list (7)\n\n");
		printf("Please select:\n");
		if (scanf("%d", &select_on_off) != EOF) {
			printf("switch OK!\n");
		} else {
			return 1;
		}
		switch(select_on_off) {
		case 1:
			init_link_list();
			break;
		case 2:
			creat_link_list(head_node);
			break;
		case 3:
			print_link_list(head_node);
			break;
		case 4:
			insert_link_list(head_node);
			break;
		case 5:
			delete_link_list(head_node);
			break;
		case 6:
			revise_link_list(head_node);
			break;
		case 7:
			find_link_list(head_node);
			break;
		default:
			printf("Select ERROR!\n");
			break;
		}
	}
	return 0;
}