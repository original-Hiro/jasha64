#找出价格(price)至少比复旦出版社(fudan)的某一本书的价格高的书的国际标准书号(isbn)
select x.isbn
from books x
where exists (select y.price
	from books y
    where y.publisher = "Fudan" and x.price > y.price
    );

#找出在2018年借出过的书籍种类(isbn)数
select isbn, count(*)
from loan
where loan_date >= '2018' #表示在2018年内或以后的日期；因为没有2019年的记录，所以这样写是正确的
group by isbn;

#找出在2018年只借出过1次的书的国际标准书号(isbn)
select isbn
from loan
where loan_date >= '2018' #表示在2018年内或以后的日期
group by isbn
having count(*) = 1;

#找出平均价格(price)最高的出版社(publisher)
#因为聚合函数不能嵌套，所以我们曲线实现这一查询
select publisher
from books
group by publisher
having avg(price) >= all(select avg(price)
	from books
	group by publisher
	);

#今天从1号员工那里借一本最贵的书，在loan中记录
insert into loan values(1, 
	(select isbn from books where price >= all(select price from books)), #可以直接把select写成insert的一个参数，但要加上括号
	'2019-03-15');