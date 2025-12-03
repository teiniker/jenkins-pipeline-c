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

    }
    post 
    {
        always 
        {
            echo 'I will always execute this!'
        }
    }
}
