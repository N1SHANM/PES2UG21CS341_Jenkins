pipeline {
    agent any
    stages {
        stage('Clone repository') {
            steps {
                checkout([$class: 'GitSCM',
                          branches: [[name: '*/main']],
                          userRemoteConfigs: [[url: 'https://github.com/N1SHANM/PES2UG21CS341_Jenkins.git']]])
            }
        }
        stage('Build') {
            steps {
                echo 'Building PES2UG21CS341-1'
                sh 'g++ main.cpp -o output'
            }
        }
        stage('Test') {
            steps {
                sh './output'
            }
        }
        stage('Deploy') {
            steps {
                echo 'Deploying...'
            }
        }
    }
    post {
        failure {
            echo 'Pipeline failed'
        }
    }
}
