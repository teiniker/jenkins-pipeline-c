pipeline 
{
    agent any 
    
    stages 
    {
        stage('build') 
        {
            steps 
            {
                echo 'Build stage: compile all code and build an executable' 
                sh 'make'
            }
        }
        stage('test') 
        {
            steps 
            {
                echo 'Test stage: run the test cases' 
               	sh 'build/stack_test'
            }
        }
        stage('static-analysis') 
        {
            steps 
            {
                echo 'Static-analysis stage: run the cppcheck tool' 
               	sh 'cppcheck --xml --xml-version=2 SOURCE_DIRECTORY 2> cppcheck.xml --enable=all --suppress=missingIncludeSystem src/*.c test/*.c '
            }
        }
        post 
        {
            always 
            {
                cppcheck pattern: 'cppcheck.xml'
            }
        }
    }
}
