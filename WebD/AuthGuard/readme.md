# Project Name

Project Name (AuthGuard)

## Overview

AuthGuard is a full-stack application designed for user authentication and security. This project includes both a React frontend and a Node.js backend, combining to provide essential features for secure user management.

## Features

- User Registration
- User Login
- JWT Token Management
- Email Verification
- Forgot Password
- Secure User Authentication

## Prerequisites

Before you begin, ensure you have met the following requirements:

- Node.js installed
- npm (Node Package Manager) installed 
- MongoDB installed and running (for backend)
- React (for the frontend)

## Getting Started

To get started with this project, follow these steps:

### Backend (Node.js)

1. Clone this repository.
2. Navigate to the `backend` directory: `cd backend`.
3. Install the required npm packages: `npm install`.
4. Create a `.env` file in the `backend` directory and configure environment variables.
5. Start the Node.js server: `npm start`.

### Frontend (React)

1. Navigate to the `frontend` directory: `cd frontend`.
2. Install the required npm packages: `npm install`.
3. Start the React application: `npm start`.

## Configuration

You'll need to configure environment variables for your project. Create a `.env` file in both the `backend` and `frontend` directories and specify the required variables.

Here are example variables to get you started:

### Backend (.env)

- `PORT`: Port for the Node.js server (e.g., 8080)
- `MONGO_URI`: MongoDB connection string
- `JWT_SECRET`: Secret key for JWT token generation
- `EMAIL_SERVICE`: Email service provider (e.g., Gmail)
- `EMAIL_USER`: Your email address
- `EMAIL_PASS`: Your email password

### Frontend (.env)

- `REACT_APP_API_URL`: URL of your Node.js backend API
- Other frontend-related environment variables


