select student.s_id, s_name, s_birth, s_sex, x.s_score as score_01, y.s_score as score_02
from student, score x, score y
where x.s_id = student.s_id and y.s_id = student.s_id
	and x.c_id = 01 and y.c_id = 02 and x.s_score > y.s_score;

select student.s_id, s_name, avg(s_score)
from student, score
where student.s_id = score.s_id
group by score.s_id having avg(s_score) >= 60;

select count(*)
from teacher
where t_name like '李%';

select s_id, s_name, s_birth, s_sex
from student
where '张三' in (select t_name
	from teacher, course, score
	where teacher.t_id = course.t_id and course.c_id = score.c_id
    and score.s_id = student.s_id);

select s_id, s_name, s_birth, s_sex
from student
where '张三' not in (select t_name
	from teacher, course, score
	where teacher.t_id = course.t_id and course.c_id = score.c_id
    and score.s_id = student.s_id);

select s_id, s_name, s_birth, s_sex
from student
where exists (select * from course where not exists
	(select *
    from score
    where score.c_id = course.c_id and score.s_id = student.s_id));
   
select student.s_id, s_name, avg(s_score)
from student, score x
where x.s_id = student.s_id
group by student.s_id having 2 <= (select count(*)
	from score y
    where y.s_id = student.s_id and y.s_score < 60);
    #不要写成y.s_id = x.s_id，按分组依据写

select student.s_id, s_name, s_birth, s_sex
from student, score
where student.s_id = score.s_id and score.c_id = 01 and s_score < 60
order by s_score desc;