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
                sh 'make test'
               	sh 'build/test'
            }
        }
        stage('doc')
        {
            steps
            {
                echo 'Documentation stage: generate API documentation'
                sh 'make doc'
            }
        }
    }
    post 
    {
        success 
        {
            archiveArtifacts artifacts: 'build/main, build/test, doc/html/**', fingerprint: true
        }
    }
}
