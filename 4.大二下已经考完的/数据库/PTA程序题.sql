--10-1 查询学生表所有学生记录
SELECT * from stu;

--10-2 查询学生表中的女生信息
select 
    sno as "学号", sname as "姓名" 
from 
    stu 
where 
    sex = 0;

--10-3 查询姓‘李’的学生记录
select 
    sno as "学号", 
    sname as 姓名, 
    sex as 性别, 
    mno as 专业, 
    birdate as 出生日期,
    memo as 备注 
from 
    stu 
where 
    sname like "李%";

--10-4 查询平均成绩高于75分的学生
select 
    sno as 学号, avg(grade) as 平均成绩 
from 
    sc 
group by 
    sno 
having 
    平均成绩 > 75;

--10-5 查询未登记成绩的学生
select 
    sno 
from 
    sc 
where 
    grade is null and cno = "C001";

--10-6 查询同专业的学生
select 
    sno as 学号, sname as 姓名 
from 
    stu 
where 
    mno in (select mno from stu where sname = '张三') 
    and sname <> '张三';

--10-7 查询选修某两门课程的学生
select 
    sno as "学号"
from 
    sc
where 
    cno in ('C001', 'C002')
group by 
    sno
having 
    count(distinct cno) >= 2;

--10-8 添加一条学生记录
insert into 
    stu 
values
    ("S012", "周强", 1, null, null, null);

--10-9 批量插入学生记录
insert into 
    softstu(sno, sname)
select 
    sno, sname 
from 
    stu 
where 
    mno = "02";

--10-10 修改高数不及格的学生成绩
update 
    sc
set
    grade = '60'
where
    grade <= 60 
    and sc.cno in (
        select 
            cou.cno 
        from 
            cou 
        where 
            cou.cname = "高等数学"
    );

--10-11 修改女生成绩
update 
    sc
set
    grade = grade * 1.05
where
    grade <= 75
and sno in (
    select
        sno
    from
        stu
    where
        sex = 0
    );

--10-12 删除成绩为空的学生选课记录
delete from 
    sc 
where 
    grade is null;

--10-13 查询Students表中的所有系名，要求结果中系名不重复
select 
    sdept 
from 
    students 
group by 
    sdept;

--10-14 查询名字中含有“明”字的男生的学生姓名和班级
select 
    sname, class 
from 
    students 
where 
    sname like "%明%";

--10-15 查询姓名是两个字的学生信息
select 
    * 
from 
    students
where 
    CHAR_LENGTH(sname) = 2;

--10-16 计算“0000001”课程的平均分、最高分和最低分
select 
    avg(score) as 平均分, 
    max(score) as 最高分, 
    min(score) as 最低分
from 
    sc 
where 
    cno = "0000001";

--10-17 统计每个学生的选课门数和考试总成绩，并按选课门数升序排列
select 
    sno as 学号, 
    count(*) as 选课门数, 
    sum(score) as 考试总成绩
from 
    sc
group by 
    sno;

--10-18 统计不及格人数超过3人的课程号和人数
select 
    cno as 课程号, 
    count(*) as 不及格人数
from 
    sc 
where 
    score < 60 
group by 
    cno
having 
    不及格人数 >= 3;