#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *lc;
	struct node *rc;
};

struct node *ptr1,*ptr2,*ptr3,*root=NULL;
int flag=0;

void BuildTree(struct node *ptr)
{
	int opt;
	if(ptr!=NULL)
	{
		printf("\nDoes '%d' have a left child?(yes-> 1/no-> 0)\t:",ptr->data);
		scanf("%d",&opt);
		if(opt==1)
		{
			struct node *new=(struct node*)malloc(sizeof(struct node));
			printf("\nEnter left node");
			scanf("%d",&new->data);
			new->lc=new->rc=NULL;
			ptr->lc=new;
			BuildTree(ptr->lc);
		}
		printf("\nDoes '%d' have a right child?(yes-> 1/no-> 0)\t:",ptr->data);
		scanf("%d",&opt);
		if(opt==1)
		{
			struct node *new=(struct node*)malloc(sizeof(struct node));
			printf("\nEnter right node");
			scanf("%d",&new->data);
			new->lc=new->rc=NULL;
			ptr->rc=new;
			BuildTree(ptr->rc);
		}
	}
}

void Inorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		Inorder(ptr->lc);
		printf("%d ",ptr->data);
		Inorder(ptr->rc);
	}
}

void Preorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		Preorder(ptr->lc);
		Preorder(ptr->rc);
	}
}

void Postorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		Postorder(ptr->lc);
		Postorder(ptr->rc);
		printf("%d ",ptr->data);
	}
}


void Search(struct node *ptr,int key)
{
	if(ptr!=NULL && flag==0)
	{
		if(ptr->data==key)
		{
			flag=1;
			ptr2=ptr;
		}
		else
		{
			Search(ptr->lc,key);
			Search(ptr->rc,key);
		
		}
	}
}



void Insert(int item,int key)
{
	int option;
	flag=0;
	Search(root,key);
	struct node *ptr=ptr2;
	if(ptr==NULL)
		printf("\nNo Such Element Exists");
	else
	{
		if(ptr->lc==NULL || ptr->rc==NULL)
		{
			printf("\n\nDo you want to Insert as Left child(1) or Right child(0) of %d",ptr->data);
			scanf("%d",&option);
			if(option==1)	
			{	
				if(ptr->lc==NULL)
				{
					struct node *new=(struct node*)malloc(sizeof(struct node));
					new->data=item;
					new->lc=new->rc=NULL;
					ptr->lc=new;
				}
				else
				{
					printf("\nInsertion as Left Child Not Possible");	
				}
			}
			else
			{
				if(ptr->rc==NULL)
				{
					struct node *new=(struct node*)malloc(sizeof(struct node));
					new->data=item;
					new->lc=new->rc=NULL;
					ptr->rc=new;
				}
				else
				{
					printf("\nInsertion as Right Child Not Possible");	
				}
			}
		}
		else
		{
			printf("\nInsertion Not Possible");	
		}
	}
}

void SearchParent(struct node *ptr,int key,struct node *parent)
{
	if(ptr!=NULL && flag==0)
	{
		if(ptr->data==key)
		{
			flag=1;
			ptr3=parent;
			printf("%d",parent->data);
			
		}
		else
		{
			SearchParent(ptr->lc,key,ptr);
			SearchParent(ptr->rc,key,ptr);
		}
	}
}

void Delete(struct node *ptr,int item)
{
	struct node *parent;
	if(ptr==NULL)
	{
		printf("\nTree is Empty.No element to Delete.");
	}
	else
	{
		flag=0;
		SearchParent(ptr,item,NULL);
		
		parent=ptr3;
		printf("%d",parent->data);
		
		if(parent!=NULL)
		{
			ptr1=parent->lc;
			ptr2=parent->rc;
			if(ptr1!=NULL)
			{
			if(ptr1->data==item)
			{
				if(ptr1->lc==NULL && ptr1->rc==NULL)
				{
					parent->lc=NULL;
				}
				else
					printf("\nNot a leafnode. Deletion not possible");
			}
			}
			if(ptr2!=NULL)
			{
			if(ptr2->data==item)
			{
				if(ptr2->lc==NULL && ptr2->rc==NULL)
				{
					parent->rc=NULL;
				}
				else
					printf("\nNot a leafnode. Deletion not possible");
			}
			}
		}
		else
		{
			printf("\nNo element to Delete.");
		}
	}
}


void main()
{
	int data,key,item,ch,ch1;
	printf("\nEnter root node");
	scanf("%d",&data);
	
	struct node *new=(struct node*)malloc(sizeof(struct node));
	new->data=data;
	new->lc=new->rc=NULL;
	root=new;
	
	BuildTree(root);
	
	printf("\n1. INSERTION \n2.DELETION\n3.SEARCHING\n4.DISPLAY\n5.EXIT");
	
	do
	{
		printf("\n\nEnter the choice :\t");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter node to insert \t:");
				scanf("%d",&item);
				printf("Enter parent node\t:");
				scanf("%d",&key);
				Insert(item,key);
				break;
			
			case 2: printf("Enter the node to be deleted\t:");
				scanf("%d",&key);
				Delete(root,key);	
				break;
			
			case 3: flag=0;
				printf("Enter the value to be searched\t:");
				scanf("%d",&key);
				Search(root,key);
				if(flag==1)
					printf("\nNode found ");
				else 
					printf("\nNode not found");	
				break;
			
			case 4:	printf("1.INORDER\t2.PREORDER\t3.POSTORDER\nEnter the choice :\t");
				scanf("%d",&ch1);
				switch(ch1)
				{
					case 1: Inorder(root); break;
					case 2: Preorder(root); break;
					case 3: Postorder(root); break;
				}	
				break;
			
			case 5: break;
		}
	}
	while(ch!=5);
	
	
	
}
