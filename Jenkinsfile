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
                make
            }
        }
        stage('test') 
        {
            steps 
            {
                echo 'Test stage: run the test cases' 
               	build/stack_test
            }
        }
    }
}